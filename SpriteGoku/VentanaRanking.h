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

				listViewRanking->Items->Clear();

				for each(Score ^ s in lista) {
					ListViewItem^ item = gcnew ListViewItem(s->nombre);
					item->SubItems->Add(s->fecha.ToString("dd/MM/yyyy HH:mm"));
					item->SubItems->Add(s->porcentaje.ToString() + "%");
					item->SubItems->Add(s->tiempoSegundos.ToString() + "s");

					listViewRanking->Items->Add(item);

					// Resaltar el primer elemento (mejor puntaje)
					if (listViewRanking->Items->Count > 0) {
						listViewRanking->Items[0]->BackColor = Color::Gold;
						listViewRanking->Items[0]->ForeColor = Color::Black; // Cambiar color
					}

					// Resaltar el segundo elemento (segundo mejor puntaje)
					if (listViewRanking->Items->Count > 1) {
						listViewRanking->Items[1]->BackColor = Color::Silver;
					}

					// Resaltar el tercer elemento (tercer mejor puntaje)
					if (listViewRanking->Items->Count > 2) {
						listViewRanking->Items[2]->BackColor = Color::Brown;
					}
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

	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::ListView^ listViewRanking;
	private: System::Windows::Forms::ColumnHeader^ columnNombre;
	private: System::Windows::Forms::ColumnHeader^ columnFechaHora;
	private: System::Windows::Forms::ColumnHeader^ columnPorcentajeConstruccion;
	private: System::Windows::Forms::ColumnHeader^ columnTiempo;

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
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->listViewRanking = (gcnew System::Windows::Forms::ListView());
			this->columnNombre = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnFechaHora = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnPorcentajeConstruccion = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnTiempo = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(294, 394);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(118, 23);
			this->btnVolver->TabIndex = 1;
			this->btnVolver->Text = L"Volver al menu";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &VentanaRanking::btnVolver_Click);
			// 
			// listViewRanking
			// 
			this->listViewRanking->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnNombre,
					this->columnFechaHora, this->columnPorcentajeConstruccion, this->columnTiempo
			});
			this->listViewRanking->FullRowSelect = true;
			this->listViewRanking->GridLines = true;
			this->listViewRanking->HideSelection = false;
			this->listViewRanking->Location = System::Drawing::Point(43, 49);
			this->listViewRanking->Name = L"listViewRanking";
			this->listViewRanking->Size = System::Drawing::Size(614, 313);
			this->listViewRanking->TabIndex = 2;
			this->listViewRanking->UseCompatibleStateImageBehavior = false;
			this->listViewRanking->View = System::Windows::Forms::View::Details;
			// 
			// columnNombre
			// 
			this->columnNombre->Text = L"Nombre";
			this->columnNombre->Width = 120;
			// 
			// columnFechaHora
			// 
			this->columnFechaHora->Text = L"Fecha&Hora";
			this->columnFechaHora->Width = 120;
			// 
			// columnPorcentajeConstruccion
			// 
			this->columnPorcentajeConstruccion->Text = L"Porcentaje Construccion";
			this->columnPorcentajeConstruccion->Width = 160;
			// 
			// columnTiempo
			// 
			this->columnTiempo->Text = L"Tiempo";
			// 
			// VentanaRanking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 450);
			this->Controls->Add(this->listViewRanking);
			this->Controls->Add(this->btnVolver);
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
