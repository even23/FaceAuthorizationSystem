#pragma once
#include "LoginForm.h"
#include "App.h"

namespace FaceRecognitionSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			app = new App();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loginButton;
	private: System::Windows::Forms::Button^  createButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: App* app;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->createButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// loginButton
			// 
			this->loginButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loginButton->Location = System::Drawing::Point(47, 44);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(154, 42);
			this->loginButton->TabIndex = 0;
			this->loginButton->Text = L"Zaloguj";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &MainWindow::loginButton_Click);
			// 
			// createButton
			// 
			this->createButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->createButton->Location = System::Drawing::Point(47, 109);
			this->createButton->Name = L"createButton";
			this->createButton->Size = System::Drawing::Size(154, 42);
			this->createButton->TabIndex = 1;
			this->createButton->Text = L"Utw�rz konto";
			this->createButton->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->exitButton->Location = System::Drawing::Point(47, 174);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(154, 42);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Wyjd�";
			this->exitButton->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(249, 261);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->createButton);
			this->Controls->Add(this->loginButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"System Autoryzacji Dost�pu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindow::MainWindow_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		LoginForm^ loginForm = gcnew LoginForm(app);
		loginForm->ShowDialog();
		this->Show();
	}
private: System::Void MainWindow_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	delete app;
}
};
}