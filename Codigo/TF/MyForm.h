#pragma once
#include "CJuego.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		CJuego^ juego;
		Graphics^ graficador;
		BufferedGraphics^ buffer;
		

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->juego = gcnew CJuego();
			this->graficador = CreateGraphics();
			this->buffer = BufferedGraphicsManager::Current->Allocate(graficador, ClientRectangle);
			
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
			delete this->juego;
			delete this->graficador;
			delete this->buffer;
		}
	private: System::Windows::Forms::Timer^ Animacion;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Animacion = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Animacion
			// 
			this->Animacion->Enabled = true;
			this->Animacion->Tick += gcnew System::EventHandler(this, &MyForm::Animacion_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 325);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Mover_principal);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Parar);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Animacion_Tick(System::Object^ sender, System::EventArgs^ e) {
		juego->dibujar(buffer->Graphics);
		juego->dibujar_prota(buffer->Graphics);
		juego->mover_corrupt();
		juego->mover_asesino();
		juego->mover_aliado();
		buffer->Render();
		
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		juego->cambiar_escenario();
	
	}
	private: System::Void Mover_principal(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up: juego->mover_prota(3); break;
		case Keys::Down:juego->mover_prota(0); break;
		case Keys::Left:juego->mover_prota(1); break;
		case Keys::Right: juego->mover_prota(2); break;
		}
	}
	private: System::Void Parar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up: juego->parar(); break;
		case Keys::Down:juego->parar(); break;
		case Keys::Left:juego->parar(); break;
		case Keys::Right: juego->parar(); break;
		}
	}
	};
}
