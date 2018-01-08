#pragma once
#include "LoginForm.h"
#include "CameraSettingsForm.h"
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
			app = gcnew App();
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
	private: System::Windows::Forms::Button^  cameraButton;

	private: System::Windows::Forms::Button^  exitButton;
	private: App^ app;
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
			this->cameraButton = (gcnew System::Windows::Forms::Button());
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
			// cameraButton
			// 
			this->cameraButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cameraButton->Location = System::Drawing::Point(47, 109);
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(154, 42);
			this->cameraButton->TabIndex = 1;
			this->cameraButton->Text = L"Ustawienia kamery";
			this->cameraButton->UseVisualStyleBackColor = true;
			this->cameraButton->Click += gcnew System::EventHandler(this, &MainWindow::cameraButton_Click);
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
			this->exitButton->Text = L"WyjdŸ";
			this->exitButton->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(249, 261);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->cameraButton);
			this->Controls->Add(this->loginButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"System Autoryzacji Dostêpu";
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
	//SendKeys();
	//keybd_event(VK_TAB, 0, 0, 0);
	delete app;
}
private: System::Void cameraButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	CameraSettingsForm^ cameraSettingsForm = gcnew CameraSettingsForm(app);
	cameraSettingsForm->ShowDialog();
	this->Show();
}
};
}
