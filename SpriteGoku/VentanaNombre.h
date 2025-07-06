#pragma once

#include "MyForm.h"

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VentanaNombre
	/// </summary>
	public ref class VentanaNombre : public System::Windows::Forms::Form
	{
	public:
		VentanaNombre(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VentanaNombre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::TextBox^ txtNombre;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"\"Ingresa tu nombre:\"";
			// 
			// btnIniciar
			// 
			this->btnIniciar->Location = System::Drawing::Point(61, 172);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(119, 23);
			this->btnIniciar->TabIndex = 1;
			this->btnIniciar->Text = L"Iniciar juego";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &VentanaNombre::btnIniciar_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(80, 106);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 22);
			this->txtNombre->TabIndex = 2;
			// 
			// VentanaNombre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->label1);
			this->Name = L"VentanaNombre";
			this->Text = L"VentanaNombre";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombre = txtNombre->Text->Trim();
		if (nombre->Length == 0) {
			MessageBox::Show("Por favor ingresa tu nombre.");
			return;
		}

		MyForm^ juego = gcnew MyForm(nombre);
		this->Hide();
		juego->ShowDialog();
		this->Close();
	}
	};
}
