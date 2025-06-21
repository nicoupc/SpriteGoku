#pragma once

#include "CJugador.h"
#include "CMundo.h"
#include "CEnemigo.h"

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
		Bitmap^ bmp = gcnew Bitmap("Goku.png");
		array<CMundo^>^ mundos;
		int mundoActual = 2;
		int tiempoRestante = 120;              // Tiempo en segundos
		int vidas = 3;                         // Cantidad inicial de vidas
		int framesAcumulados = 0;             // Para contar tiempo usando los ticks del timer
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
		Brush^ brocha = Brushes::White;
		Stopwatch^ relojTiempo = gcnew Stopwatch();
		bool invulnerable = false;
		int tiempoInvulnerabilidad = 0;

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
			int xInicio = 700 - spriteAncho - recorrido;
			mundos[1]->agregarPatrullaSD("Boo.png", xInicio, 0, 15, 22, 12);
			mundos[0]->agregarPatrullaSD("Valkyr.png", xInicio, 0, 15, 22, 12);

			mundos[1]->agregarPerseguidor("Wolf.png", 600, 400, 9);
			mundos[0]->agregarPerseguidor("Night.png", 600, 400, 9);
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
			this->ClientSize = System::Drawing::Size(1200, 800);
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

		jugador->dibujar(buffer, bmp, invulnerable);
		mundos[mundoActual]->moverPerseguidor(jugador->obtenerX(), jugador->obtenerY());

		buffer->Graphics->DrawString("Tiempo: " + tiempoRestante.ToString() + "s", fuente, brocha, 10, 10);
		buffer->Graphics->DrawString("Vidas: " + vidas.ToString(), fuente, brocha, 10, 35);

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

		if (!invulnerable && mundos[mundoActual]->detectarColision(jugador->obtenerRectangulo())) {
			vidas--;
			invulnerable = true;
			tiempoInvulnerabilidad = 20;
		}

		if (invulnerable) {
			tiempoInvulnerabilidad--;
			if (tiempoInvulnerabilidad <= 0) {
				invulnerable = false;
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
