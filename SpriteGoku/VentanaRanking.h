#pragma once

#include "Score.h"

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VentanaRanking
	/// </summary>
	public ref class VentanaRanking : public System::Windows::Forms::Form
	{
	public:
		VentanaRanking(void)
		{
			InitializeComponent();
			cargarRanking();
		}

	private:
		void cargarRanking() {
			try {
				String^ ruta = "FILES/SCORES.bin";
				List<Score^>^ lista = Score::cargarTodos(ruta);
				Score::ordenar(lista);

				listaRanking->Items->Add(" NOMBRE        | FECHA Y HORA        | % CONST | TIEMPO (s)");
				listaRanking->Items->Add("-------------------------------------------------------------");

				for each (Score ^ s in lista) {
					String^ linea = String::Format("{0,-14} {1,-20} {2,8}% {3,12}s",
						s->nombre, s->fecha.ToString("dd/MM/yyyy HH:mm"), s->porcentaje, s->tiempoSegundos);
					listaRanking->Items->Add(linea);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar el ranking: " + ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VentanaRanking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listaRanking;
	private: System::Windows::Forms::Button^ btnVolver;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listaRanking = (gcnew System::Windows::Forms::ListBox());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listaRanking
			// 
			this->listaRanking->FormattingEnabled = true;
			this->listaRanking->ItemHeight = 16;
			this->listaRanking->Location = System::Drawing::Point(42, 65);
			this->listaRanking->Name = L"listaRanking";
			this->listaRanking->Size = System::Drawing::Size(500, 292);
			this->listaRanking->TabIndex = 0;
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(238, 396);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(118, 23);
			this->btnVolver->TabIndex = 1;
			this->btnVolver->Text = L"Volver al menu";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &VentanaRanking::btnVolver_Click);
			// 
			// VentanaRanking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 450);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->listaRanking);
			this->Name = L"VentanaRanking";
			this->Text = L"VentanaRanking";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close(); // Cierra la ventana actual
		}
	};
}
