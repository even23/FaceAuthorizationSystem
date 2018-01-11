#pragma once
#include "App.h"
#include "jackylib.h"

namespace FaceAuthorizationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	using namespace jacky_lib;

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




	private: App^ app;
	private: Thread^ cameraThread;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  kameraTab;
	private: System::Windows::Forms::TabPage^  loginTab;


	private: System::Windows::Forms::Button^  cameraOffButton;
	private: System::Windows::Forms::CheckBox^  faceDetectionCheckBox;
	private: System::Windows::Forms::CheckBox^  tanTriggsCheckBox;
	private: System::Windows::Forms::CheckBox^  histogramEqualizationCheckBox;
	private: System::Windows::Forms::CheckBox^  grayScaleCheckBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  cameraButton;

	private: System::Windows::Forms::PictureBox^  photoBox;
	private: System::Windows::Forms::Button^  acceptButton;
	private: System::Windows::Forms::Button^  takePhotoButton;
	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::Label^  passwordLabel;
	private: System::Windows::Forms::TextBox^  loginTextBox;
	private: System::Windows::Forms::Label^  loginLabel;
	private: System::Windows::Forms::Button^  deletePhotoButton;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  welcomeTab;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->welcomeTab = (gcnew System::Windows::Forms::TabPage());
			this->kameraTab = (gcnew System::Windows::Forms::TabPage());
			this->cameraOffButton = (gcnew System::Windows::Forms::Button());
			this->faceDetectionCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tanTriggsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->histogramEqualizationCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->grayScaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cameraButton = (gcnew System::Windows::Forms::Button());
			this->loginTab = (gcnew System::Windows::Forms::TabPage());
			this->deletePhotoButton = (gcnew System::Windows::Forms::Button());
			this->photoBox = (gcnew System::Windows::Forms::PictureBox());
			this->acceptButton = (gcnew System::Windows::Forms::Button());
			this->takePhotoButton = (gcnew System::Windows::Forms::Button());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->kameraTab->SuspendLayout();
			this->loginTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->welcomeTab);
			this->tabControl1->Controls->Add(this->kameraTab);
			this->tabControl1->Controls->Add(this->loginTab);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(391, 432);
			this->tabControl1->TabIndex = 3;
			this->tabControl1->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &MainWindow::tabControl1_Selected);
			// 
			// welcomeTab
			// 
			this->welcomeTab->Location = System::Drawing::Point(4, 22);
			this->welcomeTab->Name = L"welcomeTab";
			this->welcomeTab->Size = System::Drawing::Size(383, 406);
			this->welcomeTab->TabIndex = 2;
			this->welcomeTab->Text = L"Powitanie";
			this->welcomeTab->UseVisualStyleBackColor = true;
			// 
			// kameraTab
			// 
			this->kameraTab->Controls->Add(this->cameraOffButton);
			this->kameraTab->Controls->Add(this->faceDetectionCheckBox);
			this->kameraTab->Controls->Add(this->tanTriggsCheckBox);
			this->kameraTab->Controls->Add(this->histogramEqualizationCheckBox);
			this->kameraTab->Controls->Add(this->grayScaleCheckBox);
			this->kameraTab->Controls->Add(this->label1);
			this->kameraTab->Controls->Add(this->cameraButton);
			this->kameraTab->Location = System::Drawing::Point(4, 22);
			this->kameraTab->Name = L"kameraTab";
			this->kameraTab->Padding = System::Windows::Forms::Padding(3);
			this->kameraTab->Size = System::Drawing::Size(383, 406);
			this->kameraTab->TabIndex = 0;
			this->kameraTab->Text = L"Kamera";
			this->kameraTab->UseVisualStyleBackColor = true;
			// 
			// cameraOffButton
			// 
			this->cameraOffButton->Enabled = false;
			this->cameraOffButton->Location = System::Drawing::Point(148, 150);
			this->cameraOffButton->Name = L"cameraOffButton";
			this->cameraOffButton->Size = System::Drawing::Size(120, 31);
			this->cameraOffButton->TabIndex = 13;
			this->cameraOffButton->Text = L"Wy³¹cz kamerê";
			this->cameraOffButton->UseVisualStyleBackColor = true;
			this->cameraOffButton->Click += gcnew System::EventHandler(this, &MainWindow::cameraOffButton_Click);
			// 
			// faceDetectionCheckBox
			// 
			this->faceDetectionCheckBox->AutoSize = true;
			this->faceDetectionCheckBox->Checked = true;
			this->faceDetectionCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->faceDetectionCheckBox->Location = System::Drawing::Point(11, 119);
			this->faceDetectionCheckBox->Name = L"faceDetectionCheckBox";
			this->faceDetectionCheckBox->Size = System::Drawing::Size(100, 17);
			this->faceDetectionCheckBox->TabIndex = 12;
			this->faceDetectionCheckBox->Text = L"detekcja twarzy";
			this->faceDetectionCheckBox->UseVisualStyleBackColor = true;
			this->faceDetectionCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::faceDetectionCheckBox_CheckedChanged);
			// 
			// tanTriggsCheckBox
			// 
			this->tanTriggsCheckBox->AutoSize = true;
			this->tanTriggsCheckBox->Location = System::Drawing::Point(11, 96);
			this->tanTriggsCheckBox->Name = L"tanTriggsCheckBox";
			this->tanTriggsCheckBox->Size = System::Drawing::Size(162, 17);
			this->tanTriggsCheckBox->TabIndex = 11;
			this->tanTriggsCheckBox->Text = L"przetwarzanie Tana i Triggsa";
			this->tanTriggsCheckBox->UseVisualStyleBackColor = true;
			this->tanTriggsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::tanTriggsCheckBox_CheckedChanged);
			// 
			// histogramEqualizationCheckBox
			// 
			this->histogramEqualizationCheckBox->AutoSize = true;
			this->histogramEqualizationCheckBox->Enabled = false;
			this->histogramEqualizationCheckBox->Location = System::Drawing::Point(11, 73);
			this->histogramEqualizationCheckBox->Name = L"histogramEqualizationCheckBox";
			this->histogramEqualizationCheckBox->Size = System::Drawing::Size(136, 17);
			this->histogramEqualizationCheckBox->TabIndex = 10;
			this->histogramEqualizationCheckBox->Text = L"wyrównanie histogramu";
			this->histogramEqualizationCheckBox->UseVisualStyleBackColor = true;
			this->histogramEqualizationCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::histogramEqualizationCheckBox_CheckedChanged);
			// 
			// grayScaleCheckBox
			// 
			this->grayScaleCheckBox->AutoSize = true;
			this->grayScaleCheckBox->Location = System::Drawing::Point(11, 50);
			this->grayScaleCheckBox->Name = L"grayScaleCheckBox";
			this->grayScaleCheckBox->Size = System::Drawing::Size(154, 17);
			this->grayScaleCheckBox->TabIndex = 8;
			this->grayScaleCheckBox->Text = L"konwersja do skali szaroœci";
			this->grayScaleCheckBox->UseVisualStyleBackColor = true;
			this->grayScaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::grayScaleCheckBox_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(8, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 44);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Przetwarznie obrazu wykorzystywane podczas wyœwietlania:";
			// 
			// cameraButton
			// 
			this->cameraButton->Location = System::Drawing::Point(11, 150);
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(120, 31);
			this->cameraButton->TabIndex = 7;
			this->cameraButton->Text = L"W³¹cz kamerê";
			this->cameraButton->UseVisualStyleBackColor = true;
			this->cameraButton->Click += gcnew System::EventHandler(this, &MainWindow::cameraButton_Click);
			// 
			// loginTab
			// 
			this->loginTab->Controls->Add(this->deletePhotoButton);
			this->loginTab->Controls->Add(this->photoBox);
			this->loginTab->Controls->Add(this->acceptButton);
			this->loginTab->Controls->Add(this->takePhotoButton);
			this->loginTab->Controls->Add(this->passwordTextBox);
			this->loginTab->Controls->Add(this->passwordLabel);
			this->loginTab->Controls->Add(this->loginTextBox);
			this->loginTab->Controls->Add(this->loginLabel);
			this->loginTab->Location = System::Drawing::Point(4, 22);
			this->loginTab->Name = L"loginTab";
			this->loginTab->Padding = System::Windows::Forms::Padding(3);
			this->loginTab->Size = System::Drawing::Size(383, 406);
			this->loginTab->TabIndex = 1;
			this->loginTab->Text = L"Logowanie";
			this->loginTab->UseVisualStyleBackColor = true;
			// 
			// deletePhotoButton
			// 
			this->deletePhotoButton->Enabled = false;
			this->deletePhotoButton->Location = System::Drawing::Point(196, 314);
			this->deletePhotoButton->Name = L"deletePhotoButton";
			this->deletePhotoButton->Size = System::Drawing::Size(156, 38);
			this->deletePhotoButton->TabIndex = 18;
			this->deletePhotoButton->Text = L"Usuñ zdjêcie";
			this->deletePhotoButton->UseVisualStyleBackColor = true;
			this->deletePhotoButton->Click += gcnew System::EventHandler(this, &MainWindow::deletePhotoButton_Click);
			// 
			// photoBox
			// 
			this->photoBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->photoBox->Location = System::Drawing::Point(79, 84);
			this->photoBox->Name = L"photoBox";
			this->photoBox->Size = System::Drawing::Size(224, 224);
			this->photoBox->TabIndex = 17;
			this->photoBox->TabStop = false;
			// 
			// acceptButton
			// 
			this->acceptButton->Location = System::Drawing::Point(79, 358);
			this->acceptButton->Name = L"acceptButton";
			this->acceptButton->Size = System::Drawing::Size(224, 38);
			this->acceptButton->TabIndex = 16;
			this->acceptButton->Text = L"Zaloguj";
			this->acceptButton->UseVisualStyleBackColor = true;
			this->acceptButton->Click += gcnew System::EventHandler(this, &MainWindow::acceptButton_Click);
			// 
			// takePhotoButton
			// 
			this->takePhotoButton->Enabled = false;
			this->takePhotoButton->Location = System::Drawing::Point(33, 314);
			this->takePhotoButton->Name = L"takePhotoButton";
			this->takePhotoButton->Size = System::Drawing::Size(157, 38);
			this->takePhotoButton->TabIndex = 14;
			this->takePhotoButton->Text = L"Zrób zdjêcie";
			this->takePhotoButton->UseVisualStyleBackColor = true;
			this->takePhotoButton->Click += gcnew System::EventHandler(this, &MainWindow::takePhotoButton_Click);
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(147, 50);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(205, 20);
			this->passwordTextBox->TabIndex = 13;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(30, 54);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(39, 13);
			this->passwordLabel->TabIndex = 12;
			this->passwordLabel->Text = L"Has³o:";
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(147, 16);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(205, 20);
			this->loginTextBox->TabIndex = 11;
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Location = System::Drawing::Point(30, 20);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(105, 13);
			this->loginLabel->TabIndex = 10;
			this->loginLabel->Text = L"Nazwa u¿ytkownika:";
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(383, 406);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 456);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"System Autoryzacji Dostêpu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindow::MainWindow_FormClosing);
			this->tabControl1->ResumeLayout(false);
			this->kameraTab->ResumeLayout(false);
			this->kameraTab->PerformLayout();
			this->loginTab->ResumeLayout(false);
			this->loginTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void MainWindow_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (app->getVideoCaptureManager()->getIsStarted()) {
		app->getVideoCaptureManager()->setIsStarted(false);
		cameraThread->Join();
	}
	delete app;
}

private: System::Void grayScaleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	bool isChecked = grayScaleCheckBox->Checked;
	histogramEqualizationCheckBox->Enabled = isChecked;
	if (isChecked == false) {
		histogramEqualizationCheckBox->Checked = false;
	}
	app->getVideoCaptureManager()->setWithHistogramEqualization(histogramEqualizationCheckBox->Checked);
	app->getVideoCaptureManager()->setWithGrayScale(isChecked);
}

private: System::Void histogramEqualizationCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	app->getVideoCaptureManager()->setWithHistogramEqualization(histogramEqualizationCheckBox->Checked);
}
private: System::Void tanTriggsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	app->getVideoCaptureManager()->setWithTanTriggs(tanTriggsCheckBox->Checked);
}
private: System::Void faceDetectionCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	app->getVideoCaptureManager()->setWithFaceDetection(faceDetectionCheckBox->Checked);
}
private: System::Void cameraButton_Click(System::Object^  sender, System::EventArgs^  e) {
	cameraButton->Enabled = false;
	takePhotoButton->Enabled = true;
	cameraOffButton->Enabled = true;
	cameraThread = gcnew Thread(gcnew ThreadStart(app->getVideoCaptureManager(), &VideoCaptureManager::startCamera));
	cameraThread->Name = "cameraThread";
	cameraThread->Start();
}
private: System::Void cameraOffButton_Click(System::Object^  sender, System::EventArgs^  e) {
	app->getVideoCaptureManager()->setIsStarted(false);
	cameraThread->Join();
	cameraButton->Enabled = true;
	cameraOffButton->Enabled = false;
	takePhotoButton->Enabled = false;
}
private: System::Void takePhotoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mat2picture bimapconvert;
	if (app->takePhoto()) {
		deletePhotoButton->Enabled = true;
		photoBox->Image = bimapconvert.Mat2Bimap(*app->getPhotoBoxImage());
	}
	else {
		photoBox->Image = nullptr;
		deletePhotoButton->Enabled = false;
	}
	photoBox->Refresh();
}
private: System::Void tabControl1_Selected(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  e) {
}
private: System::Void acceptButton_Click(System::Object^  sender, System::EventArgs^  e) {
	str2char str2ch; // convert string use jackylib
	string login = str2ch.ConvertString2Char(loginTextBox->Text);
	string typedPassword = str2ch.ConvertString2Char(passwordTextBox->Text);
	System::String^ message;
	if (app->login(login, typedPassword)) {
		char2str ch2str; // convert string use jackylib
		User* user = app->getActiveUser();
		message = ch2str.ConvertChar2String(format("Zalogowa³eœ siê do systemu jako %s %s.", user->getName().c_str(), user->getSurname().c_str()));
		this->tabControl1->Controls->Add(this->tabPage1);
	}
	else {
		message = "Nie uda³o siê zalogowaæ do systemu.";
	}
	System::String^ caption = "Komunikat";
	MessageBoxButtons buttons = MessageBoxButtons::OK;
	System::Windows::Forms::DialogResult result;

	// Displays the MessageBox.
	result = MessageBox::Show(this, message, caption, buttons);
}
private: System::Void deletePhotoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	app->removePhoto();
	photoBox->Image = nullptr;
	deletePhotoButton->Enabled = false;
	photoBox->Refresh();
}
};
}
