#pragma once
#include"MHM_Classes.h"
namespace MHMTMSV21 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for payment
	/// </summary>
	public ref class payment : public System::Windows::Forms::Form
	{
	public:
		payment(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			paymentFare a;

			Ecn_Seats->Text = a.getEconomicSeats().ToString();
			Ex_Seats->Text = a.getExecutiveSeats().ToString();
			Bus_Seats->Text = a.getBusinessSeats().ToString();
			route->Text = gcnew System::String(a.getSchedule().c_str());
			train_name->Text = gcnew System::String(a.getTrain().c_str());
			arrival->Text = gcnew System::String(a.getSchedule().c_str());
			int aa = a.getEconomicSeats();
			int bb = a.getExecutiveSeats();
			int cc = a.getBusinessSeats();
			totalFare->Text =a.calculateFare(aa, bb, cc).ToString();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~payment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Ecn_Seats;
	private: System::Windows::Forms::Label^ Bus_Seats;
	private: System::Windows::Forms::Label^ Ex_Seats;
	private: System::Windows::Forms::Label^ route;
	private: System::Windows::Forms::Label^ train_name;
	private: System::Windows::Forms::Label^ arrival;
	private: System::Windows::Forms::Label^ totalFare;
	private: System::Windows::Forms::Button^ confirm_Ticket;
	protected:

	protected:







	private: System::Windows::Forms::Button^ cancel;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(payment::typeid));
			this->Ecn_Seats = (gcnew System::Windows::Forms::Label());
			this->Bus_Seats = (gcnew System::Windows::Forms::Label());
			this->Ex_Seats = (gcnew System::Windows::Forms::Label());
			this->route = (gcnew System::Windows::Forms::Label());
			this->train_name = (gcnew System::Windows::Forms::Label());
			this->arrival = (gcnew System::Windows::Forms::Label());
			this->totalFare = (gcnew System::Windows::Forms::Label());
			this->confirm_Ticket = (gcnew System::Windows::Forms::Button());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Ecn_Seats
			// 
			this->Ecn_Seats->AutoSize = true;
			this->Ecn_Seats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ecn_Seats->Location = System::Drawing::Point(842, 173);
			this->Ecn_Seats->Name = L"Ecn_Seats";
			this->Ecn_Seats->Size = System::Drawing::Size(20, 24);
			this->Ecn_Seats->TabIndex = 0;
			this->Ecn_Seats->Text = L"0";
			this->Ecn_Seats->Click += gcnew System::EventHandler(this, &payment::Ecn_Seats_Click);
			// 
			// Bus_Seats
			// 
			this->Bus_Seats->AutoSize = true;
			this->Bus_Seats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Bus_Seats->Location = System::Drawing::Point(842, 213);
			this->Bus_Seats->Name = L"Bus_Seats";
			this->Bus_Seats->Size = System::Drawing::Size(20, 24);
			this->Bus_Seats->TabIndex = 2;
			this->Bus_Seats->Text = L"0";
			this->Bus_Seats->Click += gcnew System::EventHandler(this, &payment::label2_Click);
			// 
			// Ex_Seats
			// 
			this->Ex_Seats->AutoSize = true;
			this->Ex_Seats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ex_Seats->Location = System::Drawing::Point(841, 262);
			this->Ex_Seats->Name = L"Ex_Seats";
			this->Ex_Seats->Size = System::Drawing::Size(20, 24);
			this->Ex_Seats->TabIndex = 3;
			this->Ex_Seats->Text = L"0";
			// 
			// route
			// 
			this->route->AutoSize = true;
			this->route->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->route->Location = System::Drawing::Point(841, 304);
			this->route->Name = L"route";
			this->route->Size = System::Drawing::Size(38, 24);
			this->route->TabIndex = 4;
			this->route->Text = L"xyz";
			// 
			// train_name
			// 
			this->train_name->AutoSize = true;
			this->train_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->train_name->Location = System::Drawing::Point(842, 343);
			this->train_name->Name = L"train_name";
			this->train_name->Size = System::Drawing::Size(41, 24);
			this->train_name->TabIndex = 5;
			this->train_name->Text = L"abc";
			// 
			// arrival
			// 
			this->arrival->AutoSize = true;
			this->arrival->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival->Location = System::Drawing::Point(842, 389);
			this->arrival->Name = L"arrival";
			this->arrival->Size = System::Drawing::Size(55, 24);
			this->arrival->TabIndex = 6;
			this->arrival->Text = L"00:00";
			// 
			// totalFare
			// 
			this->totalFare->AutoSize = true;
			this->totalFare->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalFare->Location = System::Drawing::Point(841, 433);
			this->totalFare->Name = L"totalFare";
			this->totalFare->Size = System::Drawing::Size(50, 24);
			this->totalFare->TabIndex = 7;
			this->totalFare->Text = L"0000";
			this->totalFare->Click += gcnew System::EventHandler(this, &payment::label7_Click);
			// 
			// confirm_Ticket
			// 
			this->confirm_Ticket->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirm_Ticket->Location = System::Drawing::Point(845, 527);
			this->confirm_Ticket->Name = L"confirm_Ticket";
			this->confirm_Ticket->Size = System::Drawing::Size(118, 47);
			this->confirm_Ticket->TabIndex = 8;
			this->confirm_Ticket->Text = L"Confirm";
			this->confirm_Ticket->UseVisualStyleBackColor = true;
			// 
			// cancel
			// 
			this->cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancel->Location = System::Drawing::Point(1039, 527);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(118, 47);
			this->cancel->TabIndex = 9;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &payment::cancel_Click);
			// 
			// payment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1604, 881);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->confirm_Ticket);
			this->Controls->Add(this->totalFare);
			this->Controls->Add(this->arrival);
			this->Controls->Add(this->train_name);
			this->Controls->Add(this->route);
			this->Controls->Add(this->Ex_Seats);
			this->Controls->Add(this->Bus_Seats);
			this->Controls->Add(this->Ecn_Seats);
			this->DoubleBuffered = true;
			this->Name = L"payment";
			this->Text = L"payment";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &payment::payment_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void payment_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void Ecn_Seats_Click(System::Object^ sender, System::EventArgs^ e) {
		
		DataFromSelectionClass a;

		Ecn_Seats->Text = a.getEconomicSeats().ToString();
	}
	private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}