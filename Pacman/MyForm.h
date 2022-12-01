#pragma once
#include"Controlador.h"
#include"Archivo.h"

namespace Pacman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			srand(time(NULL));
			gr = this->CreateGraphics();
			ct = BufferedGraphicsManager::Current;
			buffer = ct->Allocate(gr, this->ClientRectangle);

			bmpbonus = gcnew Bitmap("imagen\\bonus.png");
			bmppac = gcnew Bitmap("imagen\\pacman.png");
			bmppunto = gcnew Bitmap("imagen\\pacdot.png");
			file = new File();
			file->leerdatos();

			controlador = new Controlador(bmppac,bmpbonus,file->getvida());
			
			controlador->agregarPuntos(bmppunto);
			
			controlador->agregarenemigo(bmppac);

		

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


		//buffers
		Graphics^ gr;
		BufferedGraphicsContext^ ct;
		BufferedGraphics^ buffer;

		Controlador* controlador;
		Bitmap^ bmppac;
		Bitmap^ bmppunto;
		Bitmap^ bmpbonus;
		File* file;
		int contado;
		//int controladorPunto;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Timer^ timer1;
		  


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(376, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(290, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(479, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 518);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		buffer->Graphics->Clear(Color::Black);

		controlador->dibujartodo(buffer->Graphics, bmppac, bmpbonus, bmppunto);

		label1->Text ="vidas: " + Convert::ToString(controlador->getpacman()->gethp());

		label2->Text = "Puntos: " + controlador->getpuntos();

		if (controlador->getpuntos()>=10 ) {

			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			this->Close();

		}else if (controlador->getpacman()->gethp() <= 0) {

			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Close();

		}

		label3->Text = "Tiempo: "+ contado;

		controlador->movertodo(buffer->Graphics);

		controlador->colision();

		//render
		buffer->Render(gr);
	
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		switch (e->KeyCode)
		{
		case Keys::Left:

			controlador->getpacman()->mover(buffer->Graphics, 'A');
			//controlador->getZombie()->mover(buffer->Graphics, 'A');
			break;

		case Keys::Down:

			controlador->getpacman()->mover(buffer->Graphics, 'S');
			break;

		case Keys::Right:

			controlador->getpacman()->mover(buffer->Graphics, 'D');
			break;

		case Keys::Up:

			controlador->getpacman()->mover(buffer->Graphics, 'W');
			break;
		}
	
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

		
		contado++;
		//
		//
		//if (contado>5)
		//{
		//	timer2->Enabled = false;

		//}

	}
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
	//
	//controladorPunto++;
	//
	//if (controladorPunto > 10)
	//{
	//	timer3->Enabled = false;

	//}
}
};
}
