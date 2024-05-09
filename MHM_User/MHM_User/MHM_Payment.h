#ifndef Payment_H
#define Payment_H
#include"MHM_Payment_Functions.h"
#include"paymentSuccessFull.h"

namespace MHMUser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MHM_Payment
	/// </summary>
	public ref class MHM_Payment : public System::Windows::Forms::Form
	{
	public:
		MHM_Payment(UserSelection &US)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			paymentFare pf;

			Ecn_Seats->Text = US.no_of_Economic_seatsGetter().ToString();
			Ex_Seats->Text = US.no_of_Executive_seatsGetter().ToString();
			Bus_Seats->Text = US.no_of_Business_seatsGetter().ToString();
			String^ x = gcnew String(US.UserRouteGetter().c_str());
			route->Text = x;
			int j = 0;
			while (j < 3)
			{
				if(US.UserTrainGetter() == 0)
				train_name->Text = "Green Line";
				else if (US.UserTrainGetter() == 1)
				train_name->Text = "Hazara Express";
				else if(US.UserTrainGetter() == 2)
				train_name->Text = "Chiltan Express";
				j++;
			}
			x = gcnew String(US.UserScheduleGetter()+"");
			arrival->Text = x;
			int ecS = US.no_of_Economic_seatsGetter();
			int exS = US.no_of_Executive_seatsGetter();
			int bS = US.no_of_Business_seatsGetter();
			totalFare->Text = pf.calculateFare(ecS, exS, bS).ToString();
			this->ShowDialog();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MHM_Payment()
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







	private: System::Windows::Forms::Button^ cancel;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MHM_Payment::typeid));
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
			this->Ecn_Seats->Location = System::Drawing::Point(931, 218);
			this->Ecn_Seats->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Ecn_Seats->Name = L"Ecn_Seats";
			this->Ecn_Seats->Size = System::Drawing::Size(31, 33);
			this->Ecn_Seats->TabIndex = 0;
			this->Ecn_Seats->Text = L"0";
			this->Ecn_Seats->Click += gcnew System::EventHandler(this, &MHM_Payment::Ecn_Seats_Click);
			// 
			// Bus_Seats
			// 
			this->Bus_Seats->AutoSize = true;
			this->Bus_Seats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Bus_Seats->Location = System::Drawing::Point(931, 272);
			this->Bus_Seats->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Bus_Seats->Name = L"Bus_Seats";
			this->Bus_Seats->Size = System::Drawing::Size(31, 33);
			this->Bus_Seats->TabIndex = 2;
			this->Bus_Seats->Text = L"0";
			this->Bus_Seats->Click += gcnew System::EventHandler(this, &MHM_Payment::label2_Click);
			// 
			// Ex_Seats
			// 
			this->Ex_Seats->AutoSize = true;
			this->Ex_Seats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ex_Seats->Location = System::Drawing::Point(931, 325);
			this->Ex_Seats->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Ex_Seats->Name = L"Ex_Seats";
			this->Ex_Seats->Size = System::Drawing::Size(31, 33);
			this->Ex_Seats->TabIndex = 3;
			this->Ex_Seats->Text = L"0";
			this->Ex_Seats->Click += gcnew System::EventHandler(this, &MHM_Payment::Ex_Seats_Click);
			// 
			// route
			// 
			this->route->AutoSize = true;
			this->route->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->route->Location = System::Drawing::Point(931, 376);
			this->route->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->route->Name = L"route";
			this->route->Size = System::Drawing::Size(60, 33);
			this->route->TabIndex = 4;
			this->route->Text = L"xyz";
			this->route->Click += gcnew System::EventHandler(this, &MHM_Payment::route_Click);
			// 
			// train_name
			// 
			this->train_name->AutoSize = true;
			this->train_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->train_name->Location = System::Drawing::Point(933, 423);
			this->train_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->train_name->Name = L"train_name";
			this->train_name->Size = System::Drawing::Size(62, 33);
			this->train_name->TabIndex = 5;
			this->train_name->Text = L"abc";
			this->train_name->Click += gcnew System::EventHandler(this, &MHM_Payment::train_name_Click);
			// 
			// arrival
			// 
			this->arrival->AutoSize = true;
			this->arrival->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arrival->Location = System::Drawing::Point(931, 469);
			this->arrival->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->arrival->Name = L"arrival";
			this->arrival->Size = System::Drawing::Size(87, 33);
			this->arrival->TabIndex = 6;
			this->arrival->Text = L"00:00";
			this->arrival->Click += gcnew System::EventHandler(this, &MHM_Payment::arrival_Click);
			// 
			// totalFare
			// 
			this->totalFare->AutoSize = true;
			this->totalFare->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalFare->Location = System::Drawing::Point(931, 517);
			this->totalFare->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->totalFare->Name = L"totalFare";
			this->totalFare->Size = System::Drawing::Size(79, 33);
			this->totalFare->TabIndex = 7;
			this->totalFare->Text = L"0000";
			this->totalFare->Click += gcnew System::EventHandler(this, &MHM_Payment::label7_Click);
			// 
			// confirm_Ticket
			// 
			this->confirm_Ticket->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->confirm_Ticket->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirm_Ticket->Location = System::Drawing::Point(545, 656);
			this->confirm_Ticket->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->confirm_Ticket->Name = L"confirm_Ticket";
			this->confirm_Ticket->Size = System::Drawing::Size(177, 72);
			this->confirm_Ticket->TabIndex = 8;
			this->confirm_Ticket->Text = L"Confirm";
			this->confirm_Ticket->UseVisualStyleBackColor = true;
			this->confirm_Ticket->Click += gcnew System::EventHandler(this, &MHM_Payment::confirm_Ticket_Click);
			// 
			// cancel
			// 
			this->cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancel->Location = System::Drawing::Point(937, 656);
			this->cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(177, 72);
			this->cancel->TabIndex = 9;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &MHM_Payment::cancel_Click);
			// 
			// MHM_Payment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1418, 968);
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
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MHM_Payment";
			this->Text = L"MHM_Payment";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MHM_Payment::payment_Load);
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

		/*UserSelection US;

		Ecn_Seats->Text = US.getEconomicSeats().ToString();*/
	}
	private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void route_Click(System::Object^ sender, System::EventArgs^ e) {
	}	
	private: System::Void Ex_Seats_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
	}
	 
	private: System::Void confirm_Ticket_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		MHMUser::paymentSuccessFull a;
		this->Close();
	}
private: System::Void train_name_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void arrival_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
#endif