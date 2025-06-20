#pragma once

#include "CJugador.h"
#include "CMundo.h"

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		CJugador* jugador = new CJugador(300, 200);
		Bitmap^ bmp = gcnew Bitmap("Goku.png");
		array<CMundo^>^ mundos;
		int mundoActual = 2;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			mundos = gcnew array<CMundo^>(3);
			mundos[0] = gcnew CMundo("Mundo1.jpg");
			mundos[1] = gcnew CMundo("Mundo2.jpg");
			mundos[2] = gcnew CMundo("Mundo3.JPG");
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
			this->ClientSize = System::Drawing::Size(900, 600);
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
