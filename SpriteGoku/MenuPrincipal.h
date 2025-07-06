#pragma once

#include "VentanaNombre.h"
#include "VentanaCreditos.h"
#include "VentanaInstrucciones.h"

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
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
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnRanking;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnSalir;
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
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnRanking = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(18, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(308, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Chrodnobalance";
			// 
			// btnJugar
			// 
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(107, 128);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(145, 29);
			this->btnJugar->TabIndex = 1;
			this->btnJugar->Text = L"JUGAR";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnJugar_Click);
			// 
			// btnRanking
			// 
			this->btnRanking->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRanking->Location = System::Drawing::Point(107, 177);
			this->btnRanking->Name = L"btnRanking";
			this->btnRanking->Size = System::Drawing::Size(145, 29);
			this->btnRanking->TabIndex = 2;
			this->btnRanking->Text = L"Ranking";
			this->btnRanking->UseVisualStyleBackColor = true;
			this->btnRanking->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnRanking_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(107, 224);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(145, 29);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(107, 274);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(145, 29);
			this->btnCreditos->TabIndex = 4;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(107, 323);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(145, 29);
			this->btnSalir->TabIndex = 5;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnSalir_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(368, 412);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnRanking);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->label1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		VentanaNombre^ ventana = gcnew VentanaNombre();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btnRanking_Click(System::Object^ sender, System::EventArgs^ e) {
		VentanaRanking^ ventana = gcnew VentanaRanking();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		VentanaCreditos^ ventana = gcnew VentanaCreditos();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}
	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		VentanaInstrucciones^ ventana = gcnew VentanaInstrucciones();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}
};
}
