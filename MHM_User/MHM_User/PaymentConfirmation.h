#pragma once

namespace MHMTMSV21 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PaymentConfirmation
	/// </summary>
	public ref class PaymentConfirmation : public System::Windows::Forms::Form
	{
	public:
		PaymentConfirmation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PaymentConfirmation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Close;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PaymentConfirmation::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Close = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-5, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1031, 657);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your payment is Successfully Submitted";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Close
			// 
			this->Close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Close->Location = System::Drawing::Point(447, 579);
			this->Close->Name = L"Close";
			this->Close->Size = System::Drawing::Size(148, 57);
			this->Close->TabIndex = 1;
			this->Close->Text = L"Close";
			this->Close->UseVisualStyleBackColor = true;
			this->Close->Click += gcnew System::EventHandler(this, &PaymentConfirmation::Close_Click);
			// 
			// PaymentConfirmation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1028, 881);
			this->Controls->Add(this->Close);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"PaymentConfirmation";
			this->Text = L"PaymentConfirmation";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Close_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	};
}
