#pragma once
#include <vcclr.h> 
namespace UserFeedBack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for UserFeedBack
	/// </summary>
	public ref class UserFeedBack : public System::Windows::Forms::Form
	{
	public:
		UserFeedBack(void)
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
		~UserFeedBack()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ FB_textbox;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ FB_SeatNo_textbox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ rating_Excellent;
	private: System::Windows::Forms::RadioButton^ rating_Average;
	private: System::Windows::Forms::RadioButton^ rating_notSatisfied;
	private: System::Windows::Forms::Button^ FB_Submit;
	private: System::Windows::Forms::Button^ FB_Cancel;







	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FB_textbox = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->FB_SeatNo_textbox = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->rating_Excellent = (gcnew System::Windows::Forms::RadioButton());
			this->rating_Average = (gcnew System::Windows::Forms::RadioButton());
			this->rating_notSatisfied = (gcnew System::Windows::Forms::RadioButton());
			this->FB_Submit = (gcnew System::Windows::Forms::Button());
			this->FB_Cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(651, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Feedback";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::AliceBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(374, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Seat Number";
			this->label2->Click += gcnew System::EventHandler(this, &UserFeedBack::label2_Click);
			// 
			// FB_textbox
			// 
			this->FB_textbox->Location = System::Drawing::Point(575, 236);
			this->FB_textbox->Name = L"FB_textbox";
			this->FB_textbox->Size = System::Drawing::Size(400, 96);
			this->FB_textbox->TabIndex = 3;
			this->FB_textbox->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::AliceBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(374, 252);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Feedback";
			// 
			// FB_SeatNo_textbox
			// 
			this->FB_SeatNo_textbox->Location = System::Drawing::Point(575, 174);
			this->FB_SeatNo_textbox->Name = L"FB_SeatNo_textbox";
			this->FB_SeatNo_textbox->Size = System::Drawing::Size(400, 25);
			this->FB_SeatNo_textbox->TabIndex = 5;
			this->FB_SeatNo_textbox->Text = L"";
			this->FB_SeatNo_textbox->TextChanged += gcnew System::EventHandler(this, &UserFeedBack::FB_SeatNo_textbox_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::AliceBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(379, 401);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Rating";
			// 
			// rating_Excellent
			// 
			this->rating_Excellent->AutoSize = true;
			this->rating_Excellent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rating_Excellent->Location = System::Drawing::Point(575, 408);
			this->rating_Excellent->Name = L"rating_Excellent";
			this->rating_Excellent->Size = System::Drawing::Size(91, 24);
			this->rating_Excellent->TabIndex = 7;
			this->rating_Excellent->TabStop = true;
			this->rating_Excellent->Text = L"Excellent";
			this->rating_Excellent->UseVisualStyleBackColor = true;
			this->rating_Excellent->CheckedChanged += gcnew System::EventHandler(this, &UserFeedBack::rating_Excellent_CheckedChanged);
			// 
			// rating_Average
			// 
			this->rating_Average->AutoSize = true;
			this->rating_Average->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rating_Average->Location = System::Drawing::Point(701, 408);
			this->rating_Average->Name = L"rating_Average";
			this->rating_Average->Size = System::Drawing::Size(86, 24);
			this->rating_Average->TabIndex = 8;
			this->rating_Average->TabStop = true;
			this->rating_Average->Text = L"Average";
			this->rating_Average->UseVisualStyleBackColor = true;
			this->rating_Average->CheckedChanged += gcnew System::EventHandler(this, &UserFeedBack::rating_Average_CheckedChanged);
			// 
			// rating_notSatisfied
			// 
			this->rating_notSatisfied->AutoSize = true;
			this->rating_notSatisfied->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rating_notSatisfied->Location = System::Drawing::Point(821, 408);
			this->rating_notSatisfied->Name = L"rating_notSatisfied";
			this->rating_notSatisfied->Size = System::Drawing::Size(118, 24);
			this->rating_notSatisfied->TabIndex = 9;
			this->rating_notSatisfied->TabStop = true;
			this->rating_notSatisfied->Text = L"Not Satisfied";
			this->rating_notSatisfied->UseVisualStyleBackColor = true;
			this->rating_notSatisfied->CheckedChanged += gcnew System::EventHandler(this, &UserFeedBack::rating_notSatisfied_CheckedChanged);
			// 
			// FB_Submit
			// 
			this->FB_Submit->BackColor = System::Drawing::Color::Transparent;
			this->FB_Submit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->FB_Submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FB_Submit->ForeColor = System::Drawing::Color::Black;
			this->FB_Submit->Location = System::Drawing::Point(575, 544);
			this->FB_Submit->Name = L"FB_Submit";
			this->FB_Submit->Size = System::Drawing::Size(131, 47);
			this->FB_Submit->TabIndex = 10;
			this->FB_Submit->Text = L"Submit";
			this->FB_Submit->UseVisualStyleBackColor = false;
			this->FB_Submit->Click += gcnew System::EventHandler(this, &UserFeedBack::FB_Submit_Click);
			// 
			// FB_Cancel
			// 
			this->FB_Cancel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->FB_Cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FB_Cancel->ForeColor = System::Drawing::Color::Black;
			this->FB_Cancel->Location = System::Drawing::Point(754, 544);
			this->FB_Cancel->Name = L"FB_Cancel";
			this->FB_Cancel->Size = System::Drawing::Size(131, 47);
			this->FB_Cancel->TabIndex = 11;
			this->FB_Cancel->Text = L"Cancel";
			this->FB_Cancel->UseVisualStyleBackColor = true;
			this->FB_Cancel->Click += gcnew System::EventHandler(this, &UserFeedBack::FB_Cancel_Click);
			// 
			// UserFeedBack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1424, 881);
			this->Controls->Add(this->FB_Cancel);
			this->Controls->Add(this->FB_Submit);
			this->Controls->Add(this->rating_notSatisfied);
			this->Controls->Add(this->rating_Average);
			this->Controls->Add(this->rating_Excellent);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->FB_SeatNo_textbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->FB_textbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->DoubleBuffered = true;
			this->Name = L"UserFeedBack";
			this->Text = L"UserFeedBack";
			this->Load += gcnew System::EventHandler(this, &UserFeedBack::UserFeedBack_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void UserFeedBack_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void FB_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();  //close fb
	}
	public: String^ Rating;
	private: System::Void rating_Excellent_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Rating = rating_Excellent->Text;
	}
	private: System::Void rating_Average_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Rating = rating_Average->Text;
	}
	private: System::Void rating_notSatisfied_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Rating = rating_notSatisfied->Text;
	}
	private: System::Void FB_Submit_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ feedback_text = this->FB_textbox->Text;
		String^ seatNo = this->FB_SeatNo_textbox->Text;


		if (feedback_text->Length == 0) {
			MessageBox::Show("Please input some feedback");
			return;
		}

		try {
			MessageBox::Show("Working till here...");

			String^ connString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=testdb;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlCon(connString);
			sqlCon.Open();

			MessageBox::Show("Connection established...");

			String^ sqlQuery = "INSERT INTO userFb ([seatNo], [feedback], [rating]) VALUES (@seatNo, @feedback, @rating);";

			SqlCommand command(sqlQuery, % sqlCon);
			command.Parameters->AddWithValue("@feedback", feedback_text);
			command.Parameters->AddWithValue("@seatNo", seatNo);
			command.Parameters->AddWithValue("@rating", Rating);

			command.ExecuteNonQuery();

			MessageBox::Show("Feedback submitted successfully");
			this->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to add feedback: " + ex->Message, "Feedback Failure", MessageBoxButtons::OK);
		}
	}




	private: System::Void FB_SeatNo_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
