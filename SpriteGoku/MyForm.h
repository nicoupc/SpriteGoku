#pragma once

#include "CJugador.h"
#include "CMundo.h"
#include "CEnemigo.h"

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
		CJugador* jugador = new CJugador(400, 300);
		Bitmap^ bmp;
		Bitmap^ bmpEscudo;
		array<CMundo^>^ mundos;
		int mundoActual = 2;
		int tiempoRestante = 120;              // Tiempo en segundos
		int vidas = 3;                         // Cantidad inicial de vidas
		int framesAcumulados = 0;             // Para contar tiempo usando los ticks del timer
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 19, FontStyle::Bold);
		Brush^ brocha = Brushes::White;
		Stopwatch^ relojTiempo = gcnew Stopwatch();
		bool invulnerable = false;
		int tiempoInvulnerabilidad = 0;
		bool escudoActivo = false;
		int duracionEscudo = 10; // en segundos
		Stopwatch^ relojEscudo = gcnew Stopwatch();
		bool velocidadActiva = false;
		int duracionVelocidad = 5; // segundos
		Stopwatch^ relojVelocidad = gcnew Stopwatch();
		Dictionary<TipoRecursoTecnologico, int>^ inventarioTecnologico = gcnew Dictionary<TipoRecursoTecnologico, int>();
		Dictionary<TipoRecursoTecnologico, Bitmap^>^ iconosTecnologicos = gcnew Dictionary<TipoRecursoTecnologico, Bitmap^>();
		Dictionary<TipoHabilidadHumana, int>^ inventarioHumano = gcnew Dictionary<TipoHabilidadHumana, int>();
		Dictionary<TipoHabilidadHumana, Bitmap^>^ iconosHumanos = gcnew Dictionary<TipoHabilidadHumana, Bitmap^>();

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			relojTiempo->Start();
			mundos = gcnew array<CMundo^>(3);
			mundos[0] = gcnew CMundo("Mundo1.jpg");
			mundos[1] = gcnew CMundo("Mundo2.jpg");
			mundos[2] = gcnew CMundo("Mundo3.JPG");

			mundos[0]->agregarPatrullaSI("Dark.png", 10, 180, 15, 22, 12);

			mundos[1]->agregarPatrullaSI("Freezer.png", 10, 180, 15, 22, 12);

			int spriteAncho = 32;
			int recorrido = 90;
			int xInicio = 790 - spriteAncho - recorrido;
			mundos[1]->agregarPatrullaSD("Majinbuu.png", xInicio, 0, 15, 22, 12);
			mundos[0]->agregarPatrullaSD("Valkyr.png", xInicio, 0, 15, 22, 12);

			mundos[1]->agregarPerseguidor("Wolf.png", 450, 600, 8);
			mundos[0]->agregarPerseguidor("Night.png", 450, 600, 8);

			bmp = gcnew Bitmap("Goku.png");
			bmpEscudo = gcnew Bitmap("GokuEvolucionado.png");
			//bmpEscudo = gcnew Bitmap("Barril.png");

			for each (TipoRecursoTecnologico tipo in Enum::GetValues(TipoRecursoTecnologico::typeid))
				inventarioTecnologico[tipo] = 0;

			iconosTecnologicos[TipoRecursoTecnologico::Robotica] = gcnew Bitmap("Robotica.png");
			iconosTecnologicos[TipoRecursoTecnologico::InteligenciaArtificial] = gcnew Bitmap("IA.png");
			iconosTecnologicos[TipoRecursoTecnologico::BigData] = gcnew Bitmap("BigData.png");
			iconosTecnologicos[TipoRecursoTecnologico::EnergiaSostenible] = gcnew Bitmap("Panel.png");

			for each (TipoHabilidadHumana tipo in Enum::GetValues(TipoHabilidadHumana::typeid))
				inventarioHumano[tipo] = 0;

			iconosHumanos[TipoHabilidadHumana::Empatia] = gcnew Bitmap("Empatia.png");
			iconosHumanos[TipoHabilidadHumana::Etica] = gcnew Bitmap("Etica.png");
			iconosHumanos[TipoHabilidadHumana::Creatividad] = gcnew Bitmap("Creatividad.png");
			iconosHumanos[TipoHabilidadHumana::TrabajoEnEquipo] = gcnew Bitmap("Equipo.png");
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
		mundos[mundoActual]->dibujar(buffer->Graphics, this->ClientSize.Width, this->ClientSize.Height);

		jugador->mover(buffer, bmp);
		jugador->setTiempoInvulnerabilidad(tiempoInvulnerabilidad);

		jugador->dibujar(buffer, escudoActivo ? bmpEscudo : bmp, invulnerable);

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
			}
		}

		// Procesar colisión con recursos tecnológicos
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

		mundos[mundoActual]->moverPerseguidor(jugador->obtenerX(), jugador->obtenerY());

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
	}
	};
}
