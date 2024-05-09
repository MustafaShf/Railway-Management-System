#pragma once
#include"UserFeedback.h"
namespace MHMUser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for paymentSuccessFull
	/// </summary>
	public ref class paymentSuccessFull : public System::Windows::Forms::Form
	{
	public:
		paymentSuccessFull(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->ShowDialog();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~paymentSuccessFull()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ paymentSuccessClose;
	private: System::Windows::Forms::Button^ Feedback;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(paymentSuccessFull::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->paymentSuccessClose = (gcnew System::Windows::Forms::Button());
			this->Feedback = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(211, -9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1514, 863);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your payment is SuccessFully Submit";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &paymentSuccessFull::label1_Click);
			// 
			// paymentSuccessClose
			// 
			this->paymentSuccessClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->paymentSuccessClose->Location = System::Drawing::Point(853, 583);
			this->paymentSuccessClose->Name = L"paymentSuccessClose";
			this->paymentSuccessClose->Size = System::Drawing::Size(144, 79);
			this->paymentSuccessClose->TabIndex = 1;
			this->paymentSuccessClose->Text = L"Close";
			this->paymentSuccessClose->UseVisualStyleBackColor = true;
			this->paymentSuccessClose->Click += gcnew System::EventHandler(this, &paymentSuccessFull::paymentSuccessClose_Click);
			// 
			// Feedback
			// 
			this->Feedback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Feedback->Location = System::Drawing::Point(823, 720);
			this->Feedback->Name = L"Feedback";
			this->Feedback->Size = System::Drawing::Size(204, 79);
			this->Feedback->TabIndex = 2;
			this->Feedback->Text = L"Feedback";
			this->Feedback->UseVisualStyleBackColor = true;
			this->Feedback->Click += gcnew System::EventHandler(this, &paymentSuccessFull::Feedback_Click);
			// 
			// paymentSuccessFull
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1418, 968);
			this->Controls->Add(this->Feedback);
			this->Controls->Add(this->paymentSuccessClose);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"paymentSuccessFull";
			this->Text = L"paymentSuccessFull";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void paymentSuccessClose_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	
	private: System::Void Feedback_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		UserFeedBack::UserFeedBack a;
		this->Close();
	}
};
}
