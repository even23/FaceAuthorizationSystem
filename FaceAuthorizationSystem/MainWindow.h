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
	private: System::Windows::Forms::TabPage^  cameraTab;



	private: System::Windows::Forms::TabPage^  loginTab;


	private: System::Windows::Forms::Button^  cameraOffButton;
	private: System::Windows::Forms::CheckBox^  faceDetectionCheckBox;
	private: System::Windows::Forms::CheckBox^  tanTriggsCheckBox;
	private: System::Windows::Forms::CheckBox^  histogramEqualizationCheckBox;
	private: System::Windows::Forms::CheckBox^  grayScaleCheckBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  cameraButton;


	private: System::Windows::Forms::Button^  loginButton;


	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::Label^  passwordLabel;
	private: System::Windows::Forms::TextBox^  loginTextBox;
	private: System::Windows::Forms::Label^  loginLabel;
	private: System::Windows::Forms::TabPage^  accountTab;





	private: System::Windows::Forms::TabPage^  welcomeTab;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TabPage^  infoTab;
	private: System::Windows::Forms::TabPage^  helpTab;
	private: System::Windows::Forms::Button^  logoutButton;
	private: System::Windows::Forms::Button^  deleteAccount;
	private: System::Windows::Forms::Button^  saveAccount;
	private: System::Windows::Forms::TextBox^  surnameTextBox;
	private: System::Windows::Forms::Label^  surnameLabel;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::TextBox^  passwordAccountTextBox;
	private: System::Windows::Forms::Label^  passwordAccountLabel;
	private: System::Windows::Forms::TextBox^  loginAccountTextBox;
	private: System::Windows::Forms::Label^  loginAccountLabel;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  reloadButton;
	private: System::Windows::Forms::ErrorProvider^  errorProvider2;
	private: System::Windows::Forms::ErrorProvider^  errorProvider3;
	private: System::Windows::Forms::ErrorProvider^  errorProvider4;
	private: System::Windows::Forms::Button^  savePhotoButton;
	private: System::Windows::Forms::Label^  activeUserLabel;
	private: System::Windows::Forms::Label^  activeUserLoginLabel;
	private: System::Windows::Forms::Button^  deletePhotoButton;
	private: System::Windows::Forms::Button^  takePhotoButton;
	private: System::Windows::Forms::PictureBox^  photoBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  newAccountButton;








	private: System::ComponentModel::IContainer^  components;





	protected:

	protected:

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->welcomeTab = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cameraTab = (gcnew System::Windows::Forms::TabPage());
			this->faceDetectionCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tanTriggsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->histogramEqualizationCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->grayScaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->loginTab = (gcnew System::Windows::Forms::TabPage());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->infoTab = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->helpTab = (gcnew System::Windows::Forms::TabPage());
			this->accountTab = (gcnew System::Windows::Forms::TabPage());
			this->newAccountButton = (gcnew System::Windows::Forms::Button());
			this->reloadButton = (gcnew System::Windows::Forms::Button());
			this->deleteAccount = (gcnew System::Windows::Forms::Button());
			this->saveAccount = (gcnew System::Windows::Forms::Button());
			this->surnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->surnameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordAccountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordAccountLabel = (gcnew System::Windows::Forms::Label());
			this->loginAccountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginAccountLabel = (gcnew System::Windows::Forms::Label());
			this->logoutButton = (gcnew System::Windows::Forms::Button());
			this->deletePhotoButton = (gcnew System::Windows::Forms::Button());
			this->takePhotoButton = (gcnew System::Windows::Forms::Button());
			this->savePhotoButton = (gcnew System::Windows::Forms::Button());
			this->cameraOffButton = (gcnew System::Windows::Forms::Button());
			this->cameraButton = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider3 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider4 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->activeUserLabel = (gcnew System::Windows::Forms::Label());
			this->activeUserLoginLabel = (gcnew System::Windows::Forms::Label());
			this->photoBox = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->welcomeTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->cameraTab->SuspendLayout();
			this->loginTab->SuspendLayout();
			this->infoTab->SuspendLayout();
			this->accountTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->welcomeTab);
			this->tabControl1->Controls->Add(this->cameraTab);
			this->tabControl1->Controls->Add(this->loginTab);
			this->tabControl1->Controls->Add(this->infoTab);
			this->tabControl1->Controls->Add(this->helpTab);
			this->tabControl1->Controls->Add(this->accountTab);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(376, 353);
			this->tabControl1->TabIndex = 3;
			this->tabControl1->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &MainWindow::tabControl1_Selected);
			// 
			// welcomeTab
			// 
			this->welcomeTab->Controls->Add(this->label4);
			this->welcomeTab->Controls->Add(this->label3);
			this->welcomeTab->Controls->Add(this->label2);
			this->welcomeTab->Controls->Add(this->pictureBox1);
			this->welcomeTab->Location = System::Drawing::Point(4, 22);
			this->welcomeTab->Name = L"welcomeTab";
			this->welcomeTab->Size = System::Drawing::Size(368, 327);
			this->welcomeTab->TabIndex = 2;
			this->welcomeTab->Text = L"Powitanie";
			this->welcomeTab->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 252);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(328, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Temat: System Autoryzacji Dostêpu na Bazie Analizy Obrazu Twarzy";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(225, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Promotor: prof. dr hab. in¿. Przemys³aw Rokita";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 275);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Autor: Kamil Kaczmarek";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(34, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(295, 184);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// cameraTab
			// 
			this->cameraTab->Controls->Add(this->faceDetectionCheckBox);
			this->cameraTab->Controls->Add(this->tanTriggsCheckBox);
			this->cameraTab->Controls->Add(this->histogramEqualizationCheckBox);
			this->cameraTab->Controls->Add(this->grayScaleCheckBox);
			this->cameraTab->Controls->Add(this->label1);
			this->cameraTab->Location = System::Drawing::Point(4, 22);
			this->cameraTab->Name = L"cameraTab";
			this->cameraTab->Padding = System::Windows::Forms::Padding(3);
			this->cameraTab->Size = System::Drawing::Size(368, 327);
			this->cameraTab->TabIndex = 0;
			this->cameraTab->Text = L"Kamera";
			this->cameraTab->UseVisualStyleBackColor = true;
			// 
			// faceDetectionCheckBox
			// 
			this->faceDetectionCheckBox->AutoSize = true;
			this->faceDetectionCheckBox->Checked = true;
			this->faceDetectionCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->faceDetectionCheckBox->Location = System::Drawing::Point(22, 119);
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
			this->tanTriggsCheckBox->Location = System::Drawing::Point(22, 96);
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
			this->histogramEqualizationCheckBox->Location = System::Drawing::Point(22, 73);
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
			this->grayScaleCheckBox->Location = System::Drawing::Point(22, 50);
			this->grayScaleCheckBox->Name = L"grayScaleCheckBox";
			this->grayScaleCheckBox->Size = System::Drawing::Size(154, 17);
			this->grayScaleCheckBox->TabIndex = 8;
			this->grayScaleCheckBox->Text = L"konwersja do skali szaroœci";
			this->grayScaleCheckBox->UseVisualStyleBackColor = true;
			this->grayScaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::grayScaleCheckBox_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(19, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 44);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Przetwarznie obrazu wykorzystywane podczas wyœwietlania:";
			// 
			// loginTab
			// 
			this->loginTab->Controls->Add(this->loginButton);
			this->loginTab->Controls->Add(this->passwordTextBox);
			this->loginTab->Controls->Add(this->passwordLabel);
			this->loginTab->Controls->Add(this->loginTextBox);
			this->loginTab->Controls->Add(this->loginLabel);
			this->loginTab->Location = System::Drawing::Point(4, 22);
			this->loginTab->Name = L"loginTab";
			this->loginTab->Padding = System::Windows::Forms::Padding(3);
			this->loginTab->Size = System::Drawing::Size(368, 327);
			this->loginTab->TabIndex = 1;
			this->loginTab->Text = L"Logowanie";
			this->loginTab->UseVisualStyleBackColor = true;
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(109, 263);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(150, 40);
			this->loginButton->TabIndex = 16;
			this->loginButton->Text = L"Zaloguj";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &MainWindow::loginButton_Click);
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(140, 50);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(205, 20);
			this->passwordTextBox->TabIndex = 13;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(23, 54);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(39, 13);
			this->passwordLabel->TabIndex = 12;
			this->passwordLabel->Text = L"Has³o:";
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(140, 16);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(205, 20);
			this->loginTextBox->TabIndex = 11;
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Location = System::Drawing::Point(23, 20);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(105, 13);
			this->loginLabel->TabIndex = 10;
			this->loginLabel->Text = L"Nazwa u¿ytkownika:";
			// 
			// infoTab
			// 
			this->infoTab->Controls->Add(this->label7);
			this->infoTab->Controls->Add(this->label6);
			this->infoTab->Controls->Add(this->label5);
			this->infoTab->Location = System::Drawing::Point(4, 22);
			this->infoTab->Name = L"infoTab";
			this->infoTab->Size = System::Drawing::Size(368, 327);
			this->infoTab->TabIndex = 3;
			this->infoTab->Text = L"Info";
			this->infoTab->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 67);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(142, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Windows Forms CLR Project";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(95, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Visual Studio 2015";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"OpenCV Version: 3.3.1";
			// 
			// helpTab
			// 
			this->helpTab->Location = System::Drawing::Point(4, 22);
			this->helpTab->Name = L"helpTab";
			this->helpTab->Size = System::Drawing::Size(368, 327);
			this->helpTab->TabIndex = 4;
			this->helpTab->Text = L"Pomoc";
			this->helpTab->UseVisualStyleBackColor = true;
			// 
			// accountTab
			// 
			this->accountTab->Controls->Add(this->newAccountButton);
			this->accountTab->Controls->Add(this->reloadButton);
			this->accountTab->Controls->Add(this->deleteAccount);
			this->accountTab->Controls->Add(this->saveAccount);
			this->accountTab->Controls->Add(this->surnameTextBox);
			this->accountTab->Controls->Add(this->surnameLabel);
			this->accountTab->Controls->Add(this->nameTextBox);
			this->accountTab->Controls->Add(this->nameLabel);
			this->accountTab->Controls->Add(this->passwordAccountTextBox);
			this->accountTab->Controls->Add(this->passwordAccountLabel);
			this->accountTab->Controls->Add(this->loginAccountTextBox);
			this->accountTab->Controls->Add(this->loginAccountLabel);
			this->accountTab->Controls->Add(this->logoutButton);
			this->accountTab->Location = System::Drawing::Point(4, 22);
			this->accountTab->Name = L"accountTab";
			this->accountTab->Padding = System::Windows::Forms::Padding(3);
			this->accountTab->Size = System::Drawing::Size(368, 327);
			this->accountTab->TabIndex = 2;
			this->accountTab->Text = L"Nowe konto";
			this->accountTab->UseVisualStyleBackColor = true;
			// 
			// newAccountButton
			// 
			this->newAccountButton->Location = System::Drawing::Point(109, 207);
			this->newAccountButton->Name = L"newAccountButton";
			this->newAccountButton->Size = System::Drawing::Size(150, 40);
			this->newAccountButton->TabIndex = 29;
			this->newAccountButton->Text = L"Za³ó¿ konto";
			this->newAccountButton->UseVisualStyleBackColor = true;
			// 
			// reloadButton
			// 
			this->reloadButton->Location = System::Drawing::Point(22, 156);
			this->reloadButton->Name = L"reloadButton";
			this->reloadButton->Size = System::Drawing::Size(104, 27);
			this->reloadButton->TabIndex = 28;
			this->reloadButton->Text = L"Przywróæ";
			this->reloadButton->UseVisualStyleBackColor = true;
			this->reloadButton->Visible = false;
			this->reloadButton->Click += gcnew System::EventHandler(this, &MainWindow::reloadButton_Click);
			// 
			// deleteAccount
			// 
			this->deleteAccount->Location = System::Drawing::Point(242, 156);
			this->deleteAccount->Name = L"deleteAccount";
			this->deleteAccount->Size = System::Drawing::Size(104, 27);
			this->deleteAccount->TabIndex = 27;
			this->deleteAccount->Text = L"Usuñ konto";
			this->deleteAccount->UseVisualStyleBackColor = true;
			this->deleteAccount->Visible = false;
			// 
			// saveAccount
			// 
			this->saveAccount->Location = System::Drawing::Point(132, 156);
			this->saveAccount->Name = L"saveAccount";
			this->saveAccount->Size = System::Drawing::Size(104, 27);
			this->saveAccount->TabIndex = 26;
			this->saveAccount->Text = L"Zapisz";
			this->saveAccount->UseVisualStyleBackColor = true;
			this->saveAccount->Visible = false;
			this->saveAccount->Click += gcnew System::EventHandler(this, &MainWindow::saveAccount_Click);
			// 
			// surnameTextBox
			// 
			this->surnameTextBox->Location = System::Drawing::Point(140, 120);
			this->surnameTextBox->Name = L"surnameTextBox";
			this->surnameTextBox->Size = System::Drawing::Size(205, 20);
			this->surnameTextBox->TabIndex = 25;
			this->surnameTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::surnameTextBox_Validating);
			// 
			// surnameLabel
			// 
			this->surnameLabel->AutoSize = true;
			this->surnameLabel->Location = System::Drawing::Point(23, 124);
			this->surnameLabel->Name = L"surnameLabel";
			this->surnameLabel->Size = System::Drawing::Size(56, 13);
			this->surnameLabel->TabIndex = 24;
			this->surnameLabel->Text = L"Nazwisko:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(140, 85);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(205, 20);
			this->nameTextBox->TabIndex = 23;
			this->nameTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::nameTextBox_Validating);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Location = System::Drawing::Point(23, 89);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(29, 13);
			this->nameLabel->TabIndex = 22;
			this->nameLabel->Text = L"Imiê:";
			// 
			// passwordAccountTextBox
			// 
			this->passwordAccountTextBox->Location = System::Drawing::Point(140, 50);
			this->passwordAccountTextBox->Name = L"passwordAccountTextBox";
			this->passwordAccountTextBox->Size = System::Drawing::Size(205, 20);
			this->passwordAccountTextBox->TabIndex = 21;
			this->passwordAccountTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::passwordAccountTextBox_Validating);
			// 
			// passwordAccountLabel
			// 
			this->passwordAccountLabel->AutoSize = true;
			this->passwordAccountLabel->Location = System::Drawing::Point(23, 54);
			this->passwordAccountLabel->Name = L"passwordAccountLabel";
			this->passwordAccountLabel->Size = System::Drawing::Size(39, 13);
			this->passwordAccountLabel->TabIndex = 20;
			this->passwordAccountLabel->Text = L"Has³o:";
			// 
			// loginAccountTextBox
			// 
			this->loginAccountTextBox->Location = System::Drawing::Point(140, 16);
			this->loginAccountTextBox->Name = L"loginAccountTextBox";
			this->loginAccountTextBox->Size = System::Drawing::Size(205, 20);
			this->loginAccountTextBox->TabIndex = 19;
			this->loginAccountTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::loginAccountTextBox_Validating);
			// 
			// loginAccountLabel
			// 
			this->loginAccountLabel->AutoSize = true;
			this->loginAccountLabel->Location = System::Drawing::Point(23, 20);
			this->loginAccountLabel->Name = L"loginAccountLabel";
			this->loginAccountLabel->Size = System::Drawing::Size(105, 13);
			this->loginAccountLabel->TabIndex = 18;
			this->loginAccountLabel->Text = L"Nazwa u¿ytkownika:";
			// 
			// logoutButton
			// 
			this->logoutButton->Location = System::Drawing::Point(109, 263);
			this->logoutButton->Name = L"logoutButton";
			this->logoutButton->Size = System::Drawing::Size(150, 40);
			this->logoutButton->TabIndex = 17;
			this->logoutButton->Text = L"Wyloguj";
			this->logoutButton->UseVisualStyleBackColor = true;
			this->logoutButton->Visible = false;
			this->logoutButton->Click += gcnew System::EventHandler(this, &MainWindow::logoutButton_Click);
			// 
			// deletePhotoButton
			// 
			this->deletePhotoButton->Enabled = false;
			this->deletePhotoButton->Location = System::Drawing::Point(493, 297);
			this->deletePhotoButton->Name = L"deletePhotoButton";
			this->deletePhotoButton->Size = System::Drawing::Size(93, 30);
			this->deletePhotoButton->TabIndex = 21;
			this->deletePhotoButton->Text = L"Usuñ zdjêcie";
			this->deletePhotoButton->UseVisualStyleBackColor = true;
			this->deletePhotoButton->Click += gcnew System::EventHandler(this, &MainWindow::deletePhotoButton_Click);
			// 
			// takePhotoButton
			// 
			this->takePhotoButton->Enabled = false;
			this->takePhotoButton->Location = System::Drawing::Point(394, 297);
			this->takePhotoButton->Name = L"takePhotoButton";
			this->takePhotoButton->Size = System::Drawing::Size(93, 30);
			this->takePhotoButton->TabIndex = 19;
			this->takePhotoButton->Text = L"Zrób zdjêcie";
			this->takePhotoButton->UseVisualStyleBackColor = true;
			this->takePhotoButton->Click += gcnew System::EventHandler(this, &MainWindow::takePhotoButton_Click);
			// 
			// savePhotoButton
			// 
			this->savePhotoButton->Enabled = false;
			this->savePhotoButton->Location = System::Drawing::Point(592, 297);
			this->savePhotoButton->Name = L"savePhotoButton";
			this->savePhotoButton->Size = System::Drawing::Size(93, 30);
			this->savePhotoButton->TabIndex = 0;
			this->savePhotoButton->Text = L"Zapisz zdjêcie";
			this->savePhotoButton->UseVisualStyleBackColor = true;
			this->savePhotoButton->Click += gcnew System::EventHandler(this, &MainWindow::savePhotoButton_Click);
			// 
			// cameraOffButton
			// 
			this->cameraOffButton->Enabled = false;
			this->cameraOffButton->Location = System::Drawing::Point(545, 333);
			this->cameraOffButton->Name = L"cameraOffButton";
			this->cameraOffButton->Size = System::Drawing::Size(120, 31);
			this->cameraOffButton->TabIndex = 13;
			this->cameraOffButton->Text = L"Wy³¹cz kamerê";
			this->cameraOffButton->UseVisualStyleBackColor = true;
			this->cameraOffButton->Click += gcnew System::EventHandler(this, &MainWindow::cameraOffButton_Click);
			// 
			// cameraButton
			// 
			this->cameraButton->Location = System::Drawing::Point(416, 333);
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(120, 31);
			this->cameraButton->TabIndex = 7;
			this->cameraButton->Text = L"W³¹cz kamerê";
			this->cameraButton->UseVisualStyleBackColor = true;
			this->cameraButton->Click += gcnew System::EventHandler(this, &MainWindow::cameraButton_Click);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// errorProvider3
			// 
			this->errorProvider3->ContainerControl = this;
			// 
			// errorProvider4
			// 
			this->errorProvider4->ContainerControl = this;
			// 
			// activeUserLabel
			// 
			this->activeUserLabel->AutoSize = true;
			this->activeUserLabel->Location = System::Drawing::Point(430, 21);
			this->activeUserLabel->Name = L"activeUserLabel";
			this->activeUserLabel->Size = System::Drawing::Size(106, 13);
			this->activeUserLabel->TabIndex = 14;
			this->activeUserLabel->Text = L"Aktywny u¿ytkownik:";
			// 
			// activeUserLoginLabel
			// 
			this->activeUserLoginLabel->AutoSize = true;
			this->activeUserLoginLabel->Location = System::Drawing::Point(542, 21);
			this->activeUserLoginLabel->Name = L"activeUserLoginLabel";
			this->activeUserLoginLabel->Size = System::Drawing::Size(32, 13);
			this->activeUserLoginLabel->TabIndex = 15;
			this->activeUserLoginLabel->Text = L"Goœæ";
			this->activeUserLoginLabel->Click += gcnew System::EventHandler(this, &MainWindow::activeUserLoginLabel_Click);
			// 
			// photoBox
			// 
			this->photoBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->photoBox->Location = System::Drawing::Point(430, 57);
			this->photoBox->Name = L"photoBox";
			this->photoBox->Size = System::Drawing::Size(224, 224);
			this->photoBox->TabIndex = 20;
			this->photoBox->TabStop = false;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(701, 377);
			this->Controls->Add(this->savePhotoButton);
			this->Controls->Add(this->takePhotoButton);
			this->Controls->Add(this->deletePhotoButton);
			this->Controls->Add(this->activeUserLoginLabel);
			this->Controls->Add(this->photoBox);
			this->Controls->Add(this->activeUserLabel);
			this->Controls->Add(this->cameraOffButton);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->cameraButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"System Autoryzacji Dostêpu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindow::MainWindow_FormClosing);
			this->tabControl1->ResumeLayout(false);
			this->welcomeTab->ResumeLayout(false);
			this->welcomeTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->cameraTab->ResumeLayout(false);
			this->cameraTab->PerformLayout();
			this->loginTab->ResumeLayout(false);
			this->loginTab->PerformLayout();
			this->infoTab->ResumeLayout(false);
			this->infoTab->PerformLayout();
			this->accountTab->ResumeLayout(false);
			this->accountTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
			this->savePhotoButton->Enabled = true;
			photoBox->Image = bimapconvert.Mat2Bimap(*app->getTakenPhoto());
		}
		else {
			photoBox->Image = nullptr;
			deletePhotoButton->Enabled = false;
			this->savePhotoButton->Enabled = false;
		}
		photoBox->Refresh();
	}
	private: System::Void tabControl1_Selected(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  e) {
	}
	private: System::Void loginButton_Click(System::Object^  sender, System::EventArgs^  e) {
		str2char str2ch; // convert string use jackylib
		string login = str2ch.ConvertString2Char(loginTextBox->Text);
		string typedPassword = str2ch.ConvertString2Char(passwordTextBox->Text);
		System::String^ message;
		if (app->login(login, typedPassword)) {
			char2str ch2str; // convert string use jackylib
			User* user = app->getActiveUser();
			message = ch2str.ConvertChar2String(format("Zalogowa³eœ siê do systemu jako %s %s.", user->getName().c_str(), user->getSurname().c_str()));
			//this->tabControl1->Controls->Add(this->myAccountTab);
			this->accountTab->Text = "Moje konto";
			this->loginButton->Enabled = false;
			this->loginTextBox->Clear();
			this->loginTab->Enabled = false;

			this->loginAccountTextBox->Text = ch2str.ConvertChar2String(user->getLogin());
			this->passwordAccountTextBox->Text = ch2str.ConvertChar2String(user->getPassword());
			this->nameTextBox->Text = ch2str.ConvertChar2String(user->getName());
			this->surnameTextBox->Text = ch2str.ConvertChar2String(user->getSurname());

			this->reloadButton->Visible = true;
			this->saveAccount->Visible = true;
			this->deleteAccount->Visible = true;
			this->logoutButton->Visible = true;

			this->newAccountButton->Visible = false;

			this->activeUserLoginLabel->Text = ch2str.ConvertChar2String(user->getLogin());
		}
		else {
			message = "Nie uda³o siê zalogowaæ do systemu.";
		}
		this->passwordTextBox->Clear();
		System::String^ caption = "Komunikat";
		MessageBoxButtons buttons = MessageBoxButtons::OK;
		System::Windows::Forms::DialogResult result;

		// Displays the MessageBox.
		result = MessageBox::Show(this, message, caption, buttons);
		this->tabControl1->SelectedTab = this->accountTab;
	}
	private: System::Void deletePhotoButton_Click(System::Object^  sender, System::EventArgs^  e) {
		app->removePhoto();
		photoBox->Image = nullptr;
		deletePhotoButton->Enabled = false;
		savePhotoButton->Enabled = false;
		photoBox->Refresh();
	}
private: System::Void logoutButton_Click(System::Object^  sender, System::EventArgs^  e) {
	loginButton->Enabled = true;
	this->loginTab->Enabled = true;
	//this->tabControl1->Controls->Remove(this->myAccountTab);
	this->accountTab->Text = "Nowe konto";
	this->activeUserLoginLabel->Text = "Goœæ";

	this->loginAccountTextBox->Text = "";
	this->passwordAccountTextBox->Text = "";
	this->nameTextBox->Text = "";
	this->surnameTextBox->Text = "";

	this->reloadButton->Visible = false;
	this->saveAccount->Visible = false;
	this->deleteAccount->Visible = false;
	this->logoutButton->Visible = false;

	this->newAccountButton->Visible = true;
	this->tabControl1->SelectedTab = this->welcomeTab;

	app->logout();
}
private: System::Void loginAccountTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	if (loginAccountTextBox->Text == "") {
		errorProvider1->SetError(loginAccountTextBox, "Pole jest wymagane.");
		e->Cancel = true;
	}
	else {
		str2char str2ch; // convert string use jackylib
		string login = str2ch.ConvertString2Char(loginAccountTextBox->Text);
		User* user = app->getUserDAO()->getUserByLogin(login);
		if (user != nullptr && user != app->getActiveUser()) {
			errorProvider1->SetError(loginAccountTextBox, "Login musi byæ unikalny.");
		}
		else {
			errorProvider1->SetError(loginAccountTextBox, "");
		}
	}
}
private: System::Void reloadButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char2str ch2str; // convert string use jackylib
	User* user = app->getActiveUser();
	this->loginAccountTextBox->Text = ch2str.ConvertChar2String(user->getLogin());
	this->passwordAccountTextBox->Text = ch2str.ConvertChar2String(user->getPassword());
	this->nameTextBox->Text = ch2str.ConvertChar2String(user->getName());
	this->surnameTextBox->Text = ch2str.ConvertChar2String(user->getSurname());
	ValidateChildren();
}
private: System::Void saveAccount_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ValidateChildren()) {
		str2char str2ch; // convert string use jackylib
		User* user = app->getActiveUser();
		user->setName(str2ch.ConvertString2Char(nameTextBox->Text));
		user->setSurname(str2ch.ConvertString2Char(surnameTextBox->Text));
		user->setLogin(str2ch.ConvertString2Char(loginAccountTextBox->Text));
		user->setPassword(str2ch.ConvertString2Char(passwordAccountTextBox->Text));
	}
}
private: System::Void savePhotoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ message;
	string filename, directory;
	char2str ch2str; // convert string use jackylib
	if (app->savePhoto(filename, directory) == true) {
		message = ch2str.ConvertChar2String(format("Zapisano zdjêcie o nazwie %s w katalogu %s.", filename.c_str(), directory.c_str()));
	}
	else {
		message = "Nie uda³o siê zapisaæ zdjêcia.";
	}
	System::String^ caption = "Komunikat";
	MessageBoxButtons buttons = MessageBoxButtons::OK;
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show(this, message, caption, buttons);
	deletePhotoButton_Click(sender, e);	
}
private: System::Void passwordAccountTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	if (passwordAccountTextBox->Text == "") {
		errorProvider2->SetError(passwordAccountTextBox, "Pole jest wymagane.");
		e->Cancel = true;
	}
	else {
		errorProvider2->SetError(passwordAccountTextBox, "");
	}
}
private: System::Void nameTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	if (nameTextBox->Text == "") {
		errorProvider3->SetError(nameTextBox, "Pole jest wymagane.");
		e->Cancel = true;
	}
	else {
		errorProvider3->SetError(nameTextBox, "");
	}
}
private: System::Void surnameTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	if (surnameTextBox->Text == "") {
		errorProvider4->SetError(surnameTextBox, "Pole jest wymagane.");
		e->Cancel = true;
	}
	else {
		errorProvider4->SetError(surnameTextBox, "");
	}
}
private: System::Void activeUserLoginLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
//private: System::Void takePhotoButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
//	mat2picture bimapconvert;
//	if (app->takePhoto()) {
//		deletePhotoButton->Enabled = true;
//		photoBox->Image = bimapconvert.Mat2Bimap(*app->getTakenPhoto());
//	}
//	else {
//		photoBox->Image = nullptr;
//		deletePhotoButton->Enabled = false;
//	}
//	photoBox->Refresh();
//}
//private: System::Void deletePhotoButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
//	app->removePhoto();
//	photoBox->Image = nullptr;
//	deletePhotoButton->Enabled = false;
//	photoBox->Refresh();
//}
};
}
