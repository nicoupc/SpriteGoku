#pragma once

#include "CJugador.h"
#include "CMundo.h"
#include "CEnemigo.h"
#include "CPlataformaConstruccion.h"
#include "CDisparo.h"

const int ALTURA_HUD = 60;

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		CJugador^ jugador = gcnew CJugador(400, 300);
		Bitmap^ bmp;
		Bitmap^ bmpEscudo;
		array<CMundo^>^ mundos;
		int mundoActual = 2;
		int tiempoRestante; // Tiempo en segundos
		int vidas; // Cantidad inicial de vidas
		int framesAcumulados = 0; // Para contar tiempo usando los ticks del timer
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 19, FontStyle::Bold);
		Brush^ brocha = Brushes::White;
		Stopwatch^ relojTiempo = gcnew Stopwatch();
		bool invulnerable = false;
		int tiempoInvulnerabilidad = 0;
		bool escudoActivo = false;
		int duracionEscudo;
		Stopwatch^ relojEscudo = gcnew Stopwatch();
		bool velocidadActiva = false;
		int duracionVelocidad;
		Stopwatch^ relojVelocidad = gcnew Stopwatch();
		Dictionary<TipoRecursoTecnologico, int>^ inventarioTecnologico = gcnew Dictionary<TipoRecursoTecnologico, int>();
		Dictionary<TipoRecursoTecnologico, Bitmap^>^ iconosTecnologicos = gcnew Dictionary<TipoRecursoTecnologico, Bitmap^>();
		Dictionary<TipoHabilidadHumana, int>^ inventarioHumano = gcnew Dictionary<TipoHabilidadHumana, int>();
		Dictionary<TipoHabilidadHumana, Bitmap^>^ iconosHumanos = gcnew Dictionary<TipoHabilidadHumana, Bitmap^>();
		int progresoConstruccion = 0;
		int cantidadEnemigos;
		int cantidadAliados;
		List<CDisparo^>^ disparos = gcnew List<CDisparo^>();
		Bitmap^ bmpDisparo = gcnew Bitmap("Disparo.png"); // Asegurate de tener esta imagen


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Paso 1: Ruta del archivo
			String^ ruta = "FILES/PARAMETERS.txt";

			// Paso 2: Verificar si el archivo existe
			if (System::IO::File::Exists(ruta)) {
				// Paso 3: Leer todas las líneas del archivo
				array<String^>^ lineas = System::IO::File::ReadAllLines(ruta);

				// Paso 4: Procesar cada línea
				for each (String ^ linea in lineas) {
					array<String^>^ partes = linea->Split('=');
					if (partes->Length == 2) {
						String^ clave = partes[0]->Trim()->ToLower();
						String^ valor = partes[1]->Trim();

						// Paso 5: Aplicar valores según la clave
						if (clave == "duracion") {
							tiempoRestante = Int32::Parse(valor);
						}
						else if (clave == "velocidad_duracion") {
							duracionVelocidad = Int32::Parse(valor);
						}
						else if (clave == "vidas") {
							vidas = Int32::Parse(valor);
						}
						else if (clave == "enemigos") {
							cantidadEnemigos = Int32::Parse(valor);
						}
						else if (clave == "aliados") {
							cantidadAliados = Int32::Parse(valor);
						}
						else if (clave == "escudo_duracion") {
							duracionEscudo = Int32::Parse(valor);
						}
					}
				}
			}
			else {
				MessageBox::Show("No se encontró el archivo PARAMETERS.txt en la carpeta FILES.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}


			relojTiempo->Start();
			mundos = gcnew array<CMundo^>(3);
			mundos[0] = gcnew CMundo("Mundo1.jpg");
			mundos[1] = gcnew CMundo("Mundo2.jpg");
			mundos[2] = gcnew CMundo("Mundo3.JPG");

			mundos[0]->generarEnemigos(cantidadEnemigos, 1);
			mundos[1]->generarEnemigos(cantidadEnemigos, 2);

			mundos[0]->generarAliados(cantidadAliados, 1);
			mundos[1]->generarAliados(cantidadAliados, 2);

			bmp = gcnew Bitmap("Goku.png");
			bmpEscudo = gcnew Bitmap("GokuEvolucionado.png");

			for each (TipoRecursoTecnologico tipo in Enum::GetValues(TipoRecursoTecnologico::typeid)) {
				inventarioTecnologico[tipo] = 0;
			}

			iconosTecnologicos[TipoRecursoTecnologico::Robotica] = gcnew Bitmap("Robotica.png");
			iconosTecnologicos[TipoRecursoTecnologico::InteligenciaArtificial] = gcnew Bitmap("InteligenciaArtificial.png");
			iconosTecnologicos[TipoRecursoTecnologico::BigData] = gcnew Bitmap("BigData.png");
			iconosTecnologicos[TipoRecursoTecnologico::EnergiaSostenible] = gcnew Bitmap("Panel.png");

			for each (TipoHabilidadHumana tipo in Enum::GetValues(TipoHabilidadHumana::typeid)) {
				inventarioHumano[tipo] = 0;
			}

			iconosHumanos[TipoHabilidadHumana::Empatia] = gcnew Bitmap("Empatia.png");
			iconosHumanos[TipoHabilidadHumana::Etica] = gcnew Bitmap("Etica.png");
			iconosHumanos[TipoHabilidadHumana::Creatividad] = gcnew Bitmap("Creatividad.png");
			iconosHumanos[TipoHabilidadHumana::TrabajoEnEquipo] = gcnew Bitmap("TrabajoEnEquipo.png");
		}

		TipoHabilidadHumana convertirAHabilidadHumana(TipoDeRecurso tipo) {
			switch (tipo) {
			case TipoDeRecurso::Empatia: return TipoHabilidadHumana::Empatia;
			case TipoDeRecurso::Etica: return TipoHabilidadHumana::Etica;
			case TipoDeRecurso::Creatividad: return TipoHabilidadHumana::Creatividad;
			case TipoDeRecurso::TrabajoEnEquipo: return TipoHabilidadHumana::TrabajoEnEquipo;
			default:
				throw gcnew Exception("TipoDeRecurso no corresponde a una habilidad humana.");
			}
		}

		TipoRecursoTecnologico convertirATecnologico(TipoDeRecurso tipo) {
			switch (tipo) {
			case TipoDeRecurso::Robotica: return TipoRecursoTecnologico::Robotica;
			case TipoDeRecurso::InteligenciaArtificial: return TipoRecursoTecnologico::InteligenciaArtificial;
			case TipoDeRecurso::BigData: return TipoRecursoTecnologico::BigData;
			case TipoDeRecurso::EnergiaSostenible: return TipoRecursoTecnologico::EnergiaSostenible;
			default:
				throw gcnew Exception("TipoDeRecurso no corresponde a un recurso tecnológico.");
			}
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1400, 1000);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();

		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = context->Allocate(g, this->ClientRectangle);

		buffer->Graphics->Clear(Color::White);
		mundos[mundoActual]->dibujar(buffer->Graphics, this->ClientSize.Width, this->ClientSize.Height, jugador);

		jugador->mover(buffer, bmp);
		jugador->setTiempoInvulnerabilidad(tiempoInvulnerabilidad);

		jugador->dibujar(buffer, escudoActivo ? bmpEscudo : bmp, invulnerable);

		for (int i = disparos->Count - 1; i >= 0; i--) {
			CDisparo^ d = disparos[i];
			d->mover();
			d->dibujar(buffer->Graphics);

			// Eliminar si sale de pantalla
			if (d->estaFueraPantalla(this->ClientSize.Width, this->ClientSize.Height)) {
				disparos->RemoveAt(i);
				continue;
			}

			// Detectar colisión con enemigos
			for each (CEnemigo ^ enemigo in mundos[mundoActual]->enemigos) {
				if (enemigo->getEstado() == EstadoEnemigo::Activo &&
					d->obtenerRectangulo().IntersectsWith(enemigo->obtenerRectangulo())) {
					enemigo->eliminar();
					disparos->RemoveAt(i);
					break;
				}
			}
		}

		// Procesar colisión con aliados
		for each (CAliado ^ a in mundos[mundoActual]->aliados) {
			if (a->estaVisible() && a->colisionaCon(jugador->obtenerRectangulo())) {
				a->aplicarEfecto(vidas);

				// Activar escudo si el aliado es de tipo escudo
				if (dynamic_cast<CAliadoEscudo^>(a) != nullptr) {
					relojEscudo->Restart();
					escudoActivo = true;
					invulnerable = true;
				}

				// Activar velocidad si el aliado es de tipo velocidad
				if (dynamic_cast<CAliadoVelocidad^>(a) != nullptr) {
					relojVelocidad->Restart();
					velocidadActiva = true;
					jugador->activarVelocidad(2.0f); // Velocidad x2
				}

				// Eliminar aliado después de aplicar efecto
				a->desaparecer();
			}
		}

		// Procesar colisión con recursos tecnológic	os
		for each (CRecursoTecnologico ^ recurso in mundos[mundoActual]->recursosTecnologicos) {
			if (recurso->estaVisible() && recurso->colisionaCon(jugador->obtenerRectangulo())) {
				recurso->desaparecer();
				TipoRecursoTecnologico tipo = recurso->obtenerTipo();
				inventarioTecnologico[tipo]++;

				// (Opcional) Podés mostrar un mensaje temporal aquí si querés
			}
		}

		// Procesar colisión con habilidades humanas
		for each (CRecursoHumano ^ habilidad in mundos[mundoActual]->recursosHumanos) {
			if (habilidad->estaVisible() && habilidad->colisionaCon(jugador->obtenerRectangulo())) {
				habilidad->desaparecer();
				TipoHabilidadHumana tipo = habilidad->obtenerTipo();
				inventarioHumano[tipo]++;
			}
		}

		if (mundos[mundoActual]->plataformasConstruccion != nullptr) {
			for each (CPlataformaConstruccion ^ plataforma in mundos[mundoActual]->plataformasConstruccion) {
				for each (CEspacioConstruible ^ espacio in plataforma->obtenerEspacios()) {
					if (!espacio->estaLleno() && espacio->obtenerRect().IntersectsWith(jugador->obtenerRectangulo())) {

						// Tipo de recurso que este espacio requiere
						TipoDeRecurso tipoReq = espacio->obtenerTipo();

						bool disponible = false;

						// Verificar si es recurso tecnológico o humano
						if ((int)tipoReq <= (int)TipoDeRecurso::EnergiaSostenible) {
							// Es tecnológico
							TipoRecursoTecnologico t = convertirATecnologico(tipoReq);

							if (inventarioTecnologico->ContainsKey(t) && inventarioTecnologico[t] > 0) {
								inventarioTecnologico[t]--;
								espacio->rellenar();
								plataforma->verificarConstruccion();
								disponible = true; // Recurso tecnológico usado
							}
						}
						else {
							// Es humano
							TipoHabilidadHumana h = convertirAHabilidadHumana(tipoReq);

							if (inventarioHumano->ContainsKey(h) && inventarioHumano[h] > 0) {
								inventarioHumano[h]--;
								espacio->rellenar();
								plataforma->verificarConstruccion();
								disponible = true; // Recurso humano usado
							}
						}
					}
				}

				// REVISAR PROGRESO DE CONSTRUCCIONES
				if (mundoActual == 2) {
					int plataformasTotales = mundos[2]->plataformasConstruccion->Count;
					int completadas = 0;

					for each (CPlataformaConstruccion ^ p in mundos[2]->plataformasConstruccion) {
						if (p->estaConstruida()) completadas++;
					}

					progresoConstruccion = completadas * 25;

					if (progresoConstruccion >= 100) {
						// Revisar si todas las plataformas ya fueron eliminadas visualmente
						bool todasEliminadas = true;
						for each (CPlataformaConstruccion ^ p in mundos[2]->plataformasConstruccion) {
							if (!p->estaEliminada()) {
								todasEliminadas = false;
								break;
							}
						}

						if (todasEliminadas) {
							buffer->Graphics->DrawString("¡GANASTE!", fuente, Brushes::Green, 450, 350);
							timer1->Enabled = false;
						}
					}
				}
			}
		}

		buffer->Graphics->DrawString("Tiempo: " + tiempoRestante.ToString() + "s", fuente, brocha, 5, 5);
		buffer->Graphics->DrawString("Vidas: " + vidas.ToString(), fuente, Brushes::Red, 5, 30);
		if (escudoActivo) {
			int tiempoRestante = duracionEscudo - (relojEscudo->ElapsedMilliseconds / 1000);
			buffer->Graphics->DrawString("ESCUDO: " + tiempoRestante.ToString() + "s", fuente, Brushes::LightBlue, 200, 5);
		}
		if (velocidadActiva) {
			int tiempoRestVel = duracionVelocidad - (relojVelocidad->ElapsedMilliseconds / 1000);
			buffer->Graphics->DrawString("VELOCIDAD: " + tiempoRestVel.ToString() + "s", fuente, Brushes::GreenYellow, 200, 30);
		}

		// RECURSOS TECNOLÓGICOS — ahora abajo a la izquierda
		int xHUD = 10;
		int sizeIcono = 25;
		int yHUD = this->ClientSize.Height - (sizeIcono + 8) * iconosTecnologicos->Count - 10;

		for each (TipoRecursoTecnologico tipo in Enum::GetValues(TipoRecursoTecnologico::typeid)) {
			Bitmap^ icono = iconosTecnologicos[tipo];
			int cantidad = inventarioTecnologico[tipo];

			buffer->Graphics->DrawImage(icono, xHUD, yHUD, sizeIcono, sizeIcono);
			String^ texto = "×" + cantidad.ToString();
			buffer->Graphics->DrawString(texto, fuente, Brushes::White, xHUD + sizeIcono, yHUD);
			yHUD += sizeIcono + 8;
		}

		// HABILIDADES HUMANAS — ahora arriba a la derecha
		int xHUD_H = this->ClientSize.Width - 70;
		int yHUD_H = 10;
		int sizeIcono_H = 25;

		for each (TipoHabilidadHumana tipo in Enum::GetValues(TipoHabilidadHumana::typeid)) {
			Bitmap^ icono = iconosHumanos[tipo];
			int cantidad = inventarioHumano[tipo];

			buffer->Graphics->DrawImage(icono, xHUD_H, yHUD_H, sizeIcono_H, sizeIcono_H);
			String^ texto = "×" + cantidad.ToString();
			buffer->Graphics->DrawString(texto, fuente, Brushes::White, xHUD_H + sizeIcono_H, yHUD_H);
			yHUD_H += sizeIcono_H + 8;
		}

		static int segundosPasados = 0;
		int totalSegundos = relojTiempo->ElapsedMilliseconds / 1000;

		if (totalSegundos > segundosPasados) {
			tiempoRestante--;
			segundosPasados = totalSegundos;
		}

		if (tiempoRestante <= 0 || vidas <= 0) {
			buffer->Graphics->DrawString("¡Fin del juego!", fuente, Brushes::Red, 400, 300);
			timer1->Enabled = false;
		}

		if (!invulnerable && !escudoActivo && mundos[mundoActual]->detectarColision(jugador->obtenerRectangulo())) {
			vidas--;
			invulnerable = true;
			tiempoInvulnerabilidad = 20;
		}

		if (invulnerable && !escudoActivo) {
			tiempoInvulnerabilidad--;
			if (tiempoInvulnerabilidad <= 0) {
				invulnerable = false;
			}
		}

		if (escudoActivo) {
			if (relojEscudo->ElapsedMilliseconds >= duracionEscudo * 1000) {
				escudoActivo = false;
			}
		}

		if (velocidadActiva) {
			if (relojVelocidad->ElapsedMilliseconds >= duracionVelocidad * 1000) {
				velocidadActiva = false;
				jugador->restaurarVelocidad();
			}
		}

		// Dibujar barra de progreso de construcción
		int largoMax = 200;
		int altoBarra = 20;
		int xBarra = this->ClientSize.Width - largoMax - 20;
		int yBarra = this->ClientSize.Height - 35;

		// Marco gris
		buffer->Graphics->FillRectangle(Brushes::Gray, xBarra, yBarra, largoMax, altoBarra);

		// Avance verde
		int largoActual = (progresoConstruccion * largoMax) / 100;
		buffer->Graphics->FillRectangle(Brushes::LimeGreen, xBarra, yBarra, largoActual, altoBarra);

		// Porcentaje al centro
		String^ textoPorcentaje = progresoConstruccion.ToString() + "%";
		buffer->Graphics->DrawString(textoPorcentaje, fuente, Brushes::White, xBarra - 70, yBarra - 5);

		buffer->Render(g);

		// Limpiar los recursos
		delete buffer;
		delete context;
		delete g;
	}
	private: System::Void soltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		jugador->direccion = Direcciones::Ninguna;
	}
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			jugador->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			jugador->direccion = Direcciones::Abajo;
			break;
		case Keys::Left:
			jugador->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			jugador->direccion = Direcciones::Derecha;
			break;
		default:
			jugador->direccion = Direcciones::Ninguna;
			break;
		}

		if (e->KeyCode == Keys::D1) mundoActual = 0;
		else if (e->KeyCode == Keys::D2) mundoActual = 1;
		else if (e->KeyCode == Keys::D3) mundoActual = 2;

		if (e->KeyCode == Keys::Space && escudoActivo) {
			int x = jugador->getX() + 20;
			int y = jugador->getY() + 20;
			Direcciones dir = jugador->ultimaTecla;
			CDisparo^ nuevoDisparo = gcnew CDisparo("Disparo.png", x, y, dir);
			disparos->Add(nuevoDisparo);
		}
	}
	};
}
