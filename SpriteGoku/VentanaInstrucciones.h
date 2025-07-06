#pragma once

namespace SpriteGoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VentanaInstrucciones
	/// </summary>
	public ref class VentanaInstrucciones : public System::Windows::Forms::Form
	{
	public:
		VentanaInstrucciones(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			picJugador->Image = gcnew Bitmap("Jugador.png");
			picEnemigos->Image = gcnew Bitmap("Enemigos.png");
			picAliados->Image = gcnew Bitmap("Aliados.png");
			picRecursosHumanos->Image = gcnew Bitmap("RecursosHumanos.png");
			picRecursosTech->Image = gcnew Bitmap("RecursosTech.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VentanaInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ picEnemigos;
	private: System::Windows::Forms::PictureBox^ picJugador;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ picAliados;
	private: System::Windows::Forms::PictureBox^ picRecursosTech;
	private: System::Windows::Forms::PictureBox^ picRecursosHumanos;
	private: System::Windows::Forms::Button^ btnVolver;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaInstrucciones::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->picEnemigos = (gcnew System::Windows::Forms::PictureBox());
			this->picJugador = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->picAliados = (gcnew System::Windows::Forms::PictureBox());
			this->picRecursosTech = (gcnew System::Windows::Forms::PictureBox());
			this->picRecursosHumanos = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEnemigos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picJugador))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAliados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecursosTech))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecursosHumanos))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(404, 953);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 23);
			this->button1->TabIndex = 47;
			this->button1->Text = L"Volver al menu";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(48, 551);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(154, 80);
			this->label10->TabIndex = 41;
			this->label10->Text = L"Recursos Tecnológicos:\r\n- Robótica\r\n- Inteligencia Artificial\r\n- Big Data\r\n- Ener"
				L"gía Sostenible";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(48, 433);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(357, 64);
			this->label6->TabIndex = 39;
			this->label6->Text = L"Aliados:\r\n- Aliado de vida: te otorga una vida extra.\r\n- Aliado de escudo: te vue"
				L"lve invulnerable por un tiempo.\r\n- Aliado de velocidad: duplica tu velocidad tem"
				L"poralmente.";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(48, 317);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(233, 48);
			this->label5->TabIndex = 38;
			this->label5->Text = L"Enemigos:\r\nsi te tocan, perdés una vida.\r\nEvitalos o disparales si tenés escudo.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(48, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(266, 32);
			this->label4->TabIndex = 37;
			this->label4->Text = L"Jugador: el Vigilante del Equilibrio.\r\nRecolecta recursos y construye el mundo 3."
				L"";
			// 
			// picEnemigos
			// 
			this->picEnemigos->Location = System::Drawing::Point(389, 255);
			this->picEnemigos->Name = L"picEnemigos";
			this->picEnemigos->Size = System::Drawing::Size(422, 149);
			this->picEnemigos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picEnemigos->TabIndex = 36;
			this->picEnemigos->TabStop = false;
			// 
			// picJugador
			// 
			this->picJugador->Location = System::Drawing::Point(568, 136);
			this->picJugador->Name = L"picJugador";
			this->picJugador->Size = System::Drawing::Size(80, 100);
			this->picJugador->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picJugador->TabIndex = 35;
			this->picJugador->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(386, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 16);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Objetivo del juego:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(192, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(521, 64);
			this->label2->TabIndex = 33;
			this->label2->Text = resources->GetString(L"label2.Text");
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(305, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(328, 32);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Instrucciones del juego";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(48, 676);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(145, 80);
			this->label7->TabIndex = 48;
			this->label7->Text = L"Habilidades Humanas:\r\n- Empatía\r\n- Ética\r\n- Creatividad\r\n- Trabajo en equipo";
			this->label7->Click += gcnew System::EventHandler(this, &VentanaInstrucciones::label7_Click);
			// 
			// picAliados
			// 
			this->picAliados->Location = System::Drawing::Point(503, 421);
			this->picAliados->Name = L"picAliados";
			this->picAliados->Size = System::Drawing::Size(250, 95);
			this->picAliados->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picAliados->TabIndex = 49;
			this->picAliados->TabStop = false;
			// 
			// picRecursosTech
			// 
			this->picRecursosTech->Location = System::Drawing::Point(452, 551);
			this->picRecursosTech->Name = L"picRecursosTech";
			this->picRecursosTech->Size = System::Drawing::Size(325, 107);
			this->picRecursosTech->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picRecursosTech->TabIndex = 50;
			this->picRecursosTech->TabStop = false;
			// 
			// picRecursosHumanos
			// 
			this->picRecursosHumanos->Location = System::Drawing::Point(452, 676);
			this->picRecursosHumanos->Name = L"picRecursosHumanos";
			this->picRecursosHumanos->Size = System::Drawing::Size(325, 98);
			this->picRecursosHumanos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picRecursosHumanos->TabIndex = 51;
			this->picRecursosHumanos->TabStop = false;
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(367, 803);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(135, 23);
			this->btnVolver->TabIndex = 52;
			this->btnVolver->Text = L"Volver al menu";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &VentanaInstrucciones::btnVolver_Click);
			// 
			// VentanaInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 920);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->picRecursosHumanos);
			this->Controls->Add(this->picRecursosTech);
			this->Controls->Add(this->picAliados);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->picEnemigos);
			this->Controls->Add(this->picJugador);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"VentanaInstrucciones";
			this->Text = L"VentanaInstrucciones";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEnemigos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picJugador))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAliados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecursosTech))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecursosHumanos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
