#pragma once
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "jackylib.h" 
#include "App.h"

#include "test.h" 

namespace FaceRecognitionSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace jacky_lib;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(App^ app)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->app = app;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  loginLabel;
	private: System::Windows::Forms::TextBox^  loginTextBox;
	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::Label^  passwordLabel;
	protected:




	private: System::Windows::Forms::Button^  takePhotoButton;

	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Button^  acceptButton;
	private: System::Windows::Forms::PictureBox^  photoBox;

	private: System::ComponentModel::IContainer^  components;
	private: App^ app;
	private: int a;
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
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->takePhotoButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->acceptButton = (gcnew System::Windows::Forms::Button());
			this->photoBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->BeginInit();
			this->SuspendLayout();
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Location = System::Drawing::Point(32, 29);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(102, 13);
			this->loginLabel->TabIndex = 0;
			this->loginLabel->Text = L"Nazwa u¿ytkownika";
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(149, 25);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(205, 20);
			this->loginTextBox->TabIndex = 1;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(149, 59);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(205, 20);
			this->passwordTextBox->TabIndex = 4;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(32, 63);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(36, 13);
			this->passwordLabel->TabIndex = 3;
			this->passwordLabel->Text = L"Has³o";
			// 
			// takePhotoButton
			// 
			this->takePhotoButton->Location = System::Drawing::Point(91, 328);
			this->takePhotoButton->Name = L"takePhotoButton";
			this->takePhotoButton->Size = System::Drawing::Size(204, 38);
			this->takePhotoButton->TabIndex = 5;
			this->takePhotoButton->Text = L"Zrób zdjêcie";
			this->takePhotoButton->UseVisualStyleBackColor = true;
			this->takePhotoButton->Click += gcnew System::EventHandler(this, &LoginForm::takePhotoButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(91, 372);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(99, 24);
			this->cancelButton->TabIndex = 7;
			this->cancelButton->Text = L"Powrót";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &LoginForm::cancelButton_Click);
			// 
			// acceptButton
			// 
			this->acceptButton->Location = System::Drawing::Point(196, 372);
			this->acceptButton->Name = L"acceptButton";
			this->acceptButton->Size = System::Drawing::Size(99, 24);
			this->acceptButton->TabIndex = 8;
			this->acceptButton->Text = L"Zaloguj";
			this->acceptButton->UseVisualStyleBackColor = true;
			this->acceptButton->Click += gcnew System::EventHandler(this, &LoginForm::acceptButton_Click);
			// 
			// photoBox
			// 
			this->photoBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->photoBox->Location = System::Drawing::Point(81, 93);
			this->photoBox->Name = L"photoBox";
			this->photoBox->Size = System::Drawing::Size(224, 224);
			this->photoBox->TabIndex = 9;
			this->photoBox->TabStop = false;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 411);
			this->Controls->Add(this->photoBox);
			this->Controls->Add(this->acceptButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->takePhotoButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->loginLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Login Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void takePhotoButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Thread^ cameraThread = gcnew Thread(gcnew ThreadStart(app->getVideoCaptureManager(), &VideoCaptureManager::startCamera));
		cameraThread->Name = "cameraThread";
		cameraThread->Start();
		VideoCapture capture;
		cv::Mat frame;
		int c;
		if (capture.open(0))
		{
			do
			{
				capture.read(frame);
				//-- 3. Apply the classifier to the frame
				if (!frame.empty())
				{
					detectAndDisplay(frame, a);
				}
				else
				{
					printf(" --(!) No captured frame -- Break!"); break;
				}
				c = waitKey(10);
				switch (c) {
				case 'x':
					mat2picture bimapconvert;
					Mat result;
					capture.read(frame);
					//if (app->takePhoto(frame, result)) {
					//	photoBox->Image = bimapconvert.Mat2Bimap(result);
					//}
					//else {
					//	photoBox->Image = nullptr;
					//}
					photoBox->Refresh();
					break;
				}
			} while ((char)c != 'c');
		}
		destroyWindow("TEST");
	}
	private: System::Void acceptButton_Click(System::Object^  sender, System::EventArgs^  e) {
		str2char str2ch; // convert string use jackylib
		string login = str2ch.ConvertString2Char(loginTextBox->Text);
		string typedPassword = str2ch.ConvertString2Char(passwordTextBox->Text);
		System::String^ message;
		if (app->login(login, typedPassword)) {
			message = "Zalogowa³eœ siê do systemu";

		}
		else {
			message = "Nie uda³o siê zalogowaæ do systemu";
		}
		System::String^ caption = "Komunikat";
		MessageBoxButtons buttons = MessageBoxButtons::YesNo;
		System::Windows::Forms::DialogResult result;

		// Displays the MessageBox.
		result = MessageBox::Show(this, message, caption, buttons);
	}
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	a = (a++) % 2;
}
};
}
