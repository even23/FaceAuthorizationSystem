#pragma once

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include "App.h"

namespace FaceRecognitionSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for CameraSettingsForm
	/// </summary>
	public ref class CameraSettingsForm : public System::Windows::Forms::Form
	{
	public:
		CameraSettingsForm(App^ _app)
		{
			InitializeComponent();
			app = _app;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CameraSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  cameraButton;
	private: System::Windows::Forms::CheckBox^  grayScaleCheckBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  histogramEqualizationCheckBox;
	private: System::Windows::Forms::CheckBox^  tanTriggsCheckBox;
	private: System::Windows::Forms::CheckBox^  faceDetectionCheckBox;



	private: System::Windows::Forms::Button^  cameraOffButton;

	private: System::Windows::Forms::Button^  backButton;

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: App^ app;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cameraButton = (gcnew System::Windows::Forms::Button());
			this->grayScaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->histogramEqualizationCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tanTriggsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->faceDetectionCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->cameraOffButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cameraButton
			// 
			this->cameraButton->Location = System::Drawing::Point(15, 146);
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(120, 31);
			this->cameraButton->TabIndex = 0;
			this->cameraButton->Text = L"W³¹cz kamerê";
			this->cameraButton->UseVisualStyleBackColor = true;
			this->cameraButton->Click += gcnew System::EventHandler(this, &CameraSettingsForm::cameraButton_Click);
			// 
			// grayScaleCheckBox
			// 
			this->grayScaleCheckBox->AutoSize = true;
			this->grayScaleCheckBox->Location = System::Drawing::Point(15, 46);
			this->grayScaleCheckBox->Name = L"grayScaleCheckBox";
			this->grayScaleCheckBox->Size = System::Drawing::Size(154, 17);
			this->grayScaleCheckBox->TabIndex = 1;
			this->grayScaleCheckBox->Text = L"konwersja do skali szaroœci";
			this->grayScaleCheckBox->UseVisualStyleBackColor = true;
			this->grayScaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CameraSettingsForm::grayScaleCheckBox_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 44);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Przetwarznie obrazu wykorzystywane podczas wyœiwietlania:";
			// 
			// histogramEqualizationCheckBox
			// 
			this->histogramEqualizationCheckBox->AutoSize = true;
			this->histogramEqualizationCheckBox->Enabled = false;
			this->histogramEqualizationCheckBox->Location = System::Drawing::Point(15, 69);
			this->histogramEqualizationCheckBox->Name = L"histogramEqualizationCheckBox";
			this->histogramEqualizationCheckBox->Size = System::Drawing::Size(136, 17);
			this->histogramEqualizationCheckBox->TabIndex = 3;
			this->histogramEqualizationCheckBox->Text = L"wyrównanie histogramu";
			this->histogramEqualizationCheckBox->UseVisualStyleBackColor = true;
			this->histogramEqualizationCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CameraSettingsForm::histogramEqualizationCheckBox_CheckedChanged_1);
			// 
			// tanTriggsCheckBox
			// 
			this->tanTriggsCheckBox->AutoSize = true;
			this->tanTriggsCheckBox->Location = System::Drawing::Point(15, 92);
			this->tanTriggsCheckBox->Name = L"tanTriggsCheckBox";
			this->tanTriggsCheckBox->Size = System::Drawing::Size(162, 17);
			this->tanTriggsCheckBox->TabIndex = 4;
			this->tanTriggsCheckBox->Text = L"przetwarzanie Tana i Triggsa";
			this->tanTriggsCheckBox->UseVisualStyleBackColor = true;
			this->tanTriggsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CameraSettingsForm::tanTriggsCheckBox_CheckedChanged);
			// 
			// faceDetectionCheckBox
			// 
			this->faceDetectionCheckBox->AutoSize = true;
			this->faceDetectionCheckBox->Checked = true;
			this->faceDetectionCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->faceDetectionCheckBox->Location = System::Drawing::Point(15, 115);
			this->faceDetectionCheckBox->Name = L"faceDetectionCheckBox";
			this->faceDetectionCheckBox->Size = System::Drawing::Size(100, 17);
			this->faceDetectionCheckBox->TabIndex = 5;
			this->faceDetectionCheckBox->Text = L"detekcja twarzy";
			this->faceDetectionCheckBox->UseVisualStyleBackColor = true;
			this->faceDetectionCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CameraSettingsForm::faceDetectionCheckBox_CheckedChanged);
			// 
			// cameraOffButton
			// 
			this->cameraOffButton->Enabled = false;
			this->cameraOffButton->Location = System::Drawing::Point(152, 146);
			this->cameraOffButton->Name = L"cameraOffButton";
			this->cameraOffButton->Size = System::Drawing::Size(120, 31);
			this->cameraOffButton->TabIndex = 6;
			this->cameraOffButton->Text = L"Wy³¹cz kamerê";
			this->cameraOffButton->UseVisualStyleBackColor = true;
			this->cameraOffButton->Click += gcnew System::EventHandler(this, &CameraSettingsForm::cameraOffButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(78, 183);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(120, 31);
			this->backButton->TabIndex = 7;
			this->backButton->Text = L"Powrót";
			this->backButton->UseVisualStyleBackColor = true;
			// 
			// CameraSettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 217);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->cameraOffButton);
			this->Controls->Add(this->faceDetectionCheckBox);
			this->Controls->Add(this->tanTriggsCheckBox);
			this->Controls->Add(this->histogramEqualizationCheckBox);
			this->Controls->Add(this->grayScaleCheckBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cameraButton);
			this->Name = L"CameraSettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CameraSettingsForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CameraSettingsForm::CameraSettingsForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CameraSettingsForm::CameraSettingsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void grayScaleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		bool isChecked = grayScaleCheckBox->Checked;
		histogramEqualizationCheckBox->Enabled = isChecked;
		if (isChecked == false) {
			histogramEqualizationCheckBox->Checked = false;
		}
		app->getVideoCaptureManager()->setWithHistogramEqualization(histogramEqualizationCheckBox->Checked);
		app->getVideoCaptureManager()->setWithGrayScale(isChecked);
			
	}
private: System::Void histogramEqualizationCheckBox_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
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
	cameraOffButton->Enabled = true;
	//app->getVideoCaptureManager()->startCamera();
	Thread^ cameraThread = gcnew Thread(gcnew ThreadStart(app->getVideoCaptureManager(), &VideoCaptureManager::startCamera));
	cameraThread->Name = "cameraThread";
	cameraThread->Start();
}
private: System::Void cameraOffButton_Click(System::Object^  sender, System::EventArgs^  e) {
	app->getVideoCaptureManager()->setIsStarted(false);
	cameraButton->Enabled = true;
	cameraOffButton->Enabled = false;
}

private: System::Void CameraSettingsForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	app->getVideoCaptureManager()->setIsStarted(false);
}
private: System::Void CameraSettingsForm_Load(System::Object^  sender, System::EventArgs^  e) {
	histogramEqualizationCheckBox->Checked = app->getVideoCaptureManager()->getWithHistogramEqualization();
	grayScaleCheckBox->Checked = app->getVideoCaptureManager()->getWithGrayScale();
	if (grayScaleCheckBox->Checked) {
		histogramEqualizationCheckBox->Enabled = true;
		histogramEqualizationCheckBox->Checked = app->getVideoCaptureManager()->getWithHistogramEqualization();
	}
	tanTriggsCheckBox->Checked = app->getVideoCaptureManager()->getWithTanTriggs();
	faceDetectionCheckBox->Checked = app->getVideoCaptureManager()->getWithFaceDetection();
}
};
}
