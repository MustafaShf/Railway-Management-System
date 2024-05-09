#ifndef USER_SELECTION_H
#define USER_SELECTION_H
#include"MHM_User_Functions.h"
#include"MHM_Payment.h"

UserDataRetriever* b;
UserSelection US;
int rowCount=0;
int index=0;

namespace MHMUser {

	/// <summary>
	/// Summary for MHM_User
	/// </summary>
	public ref class MHM_User : public System::Windows::Forms::Form
	{
	public:
		MHM_User(void)
		{
			//-------------------------------------INITIALIZE AND EARLY STUFF ETC----------------------------------
			InitializeComponent();
			
			rowCount = US.GetData(b);

			//Available RouteListBox Data/dynamically displaying the database's info
			int i = 0;
			while (i < rowCount)
			{
				// Adds available option to routesListbox
				if (b[i].availabilityUserGetter() == 1)
				{
					String^ itemText = gcnew String((b[i].startUserGetter() + " to " + b[i].endUserGetter()).c_str());
					UserRoutesList->Items->Add(itemText);
				}
				i++;
			}
			//event handler (dynamically implements the event function)
			this->UserRoutesList->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MHM_User::UserRoutesList_ItemCheck);

			
			//event handler (dynamically implements the event function)
			this->UserScheduleList->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MHM_User::UserScheduleList_ItemCheck);

			//event handler (dynamically implements the event function)
			this->UserTrainList->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MHM_User::UserTrainList_ItemCheck);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MHM_User()
		{
			//----------------------------------Destructor/Delete all pointers etc.-----------------------------------
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ UserRoutes;
	private: System::Windows::Forms::PictureBox^ UserRoutesBg;
	private: System::Windows::Forms::Button^ ContinueU1;

	private: System::Windows::Forms::CheckedListBox^ UserRoutesList;
	private: System::Windows::Forms::Button^ UserSchedule;
	private: System::Windows::Forms::PictureBox^ UserSchedBG;
	private: System::Windows::Forms::Button^ ContinueU2;
	private: System::Windows::Forms::CheckedListBox^ UserScheduleList;
	private: System::Windows::Forms::Button^ UserTrains;
	private: System::Windows::Forms::PictureBox^ UserTrainsBG;
	private: System::Windows::Forms::Button^ ContinueU3;
	private: System::Windows::Forms::CheckedListBox^ UserTrainList;
	private: System::Windows::Forms::Button^ UserSelectsSeats;
	private: System::Windows::Forms::PictureBox^ seatSelectBg;
	private: System::Windows::Forms::PictureBox^ seatss;

	private: System::Windows::Forms::Button^ ContinueU4;
	private: System::Windows::Forms::Button^ B1;
	private: System::Windows::Forms::Button^ B2;
	private: System::Windows::Forms::Button^ Ec1;
	private: System::Windows::Forms::Button^ Ec4;



	private: System::Windows::Forms::Button^ B4;

	private: System::Windows::Forms::Button^ B3;
	private: System::Windows::Forms::Button^ Ec3;

	private: System::Windows::Forms::Button^ Ec2;
	private: System::Windows::Forms::Button^ Ex1;
	private: System::Windows::Forms::Button^ Ex6;
	private: System::Windows::Forms::Button^ Ex7;
	private: System::Windows::Forms::Button^ Ex8;
	private: System::Windows::Forms::Button^ Ex4;
	private: System::Windows::Forms::Button^ Ex3;
	private: System::Windows::Forms::Button^ Ex2;
	private: System::Windows::Forms::Button^ Ex5;
	private: System::Windows::Forms::Button^ kaka;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MHM_User::typeid));
			this->UserRoutes = (gcnew System::Windows::Forms::Button());
			this->UserRoutesBg = (gcnew System::Windows::Forms::PictureBox());
			this->ContinueU1 = (gcnew System::Windows::Forms::Button());
			this->UserRoutesList = (gcnew System::Windows::Forms::CheckedListBox());
			this->UserSchedule = (gcnew System::Windows::Forms::Button());
			this->UserSchedBG = (gcnew System::Windows::Forms::PictureBox());
			this->ContinueU2 = (gcnew System::Windows::Forms::Button());
			this->UserScheduleList = (gcnew System::Windows::Forms::CheckedListBox());
			this->UserTrains = (gcnew System::Windows::Forms::Button());
			this->UserTrainsBG = (gcnew System::Windows::Forms::PictureBox());
			this->ContinueU3 = (gcnew System::Windows::Forms::Button());
			this->UserTrainList = (gcnew System::Windows::Forms::CheckedListBox());
			this->UserSelectsSeats = (gcnew System::Windows::Forms::Button());
			this->seatSelectBg = (gcnew System::Windows::Forms::PictureBox());
			this->seatss = (gcnew System::Windows::Forms::PictureBox());
			this->ContinueU4 = (gcnew System::Windows::Forms::Button());
			this->B1 = (gcnew System::Windows::Forms::Button());
			this->B2 = (gcnew System::Windows::Forms::Button());
			this->Ec1 = (gcnew System::Windows::Forms::Button());
			this->Ec4 = (gcnew System::Windows::Forms::Button());
			this->B4 = (gcnew System::Windows::Forms::Button());
			this->B3 = (gcnew System::Windows::Forms::Button());
			this->Ec3 = (gcnew System::Windows::Forms::Button());
			this->Ec2 = (gcnew System::Windows::Forms::Button());
			this->Ex1 = (gcnew System::Windows::Forms::Button());
			this->Ex6 = (gcnew System::Windows::Forms::Button());
			this->Ex7 = (gcnew System::Windows::Forms::Button());
			this->Ex8 = (gcnew System::Windows::Forms::Button());
			this->Ex4 = (gcnew System::Windows::Forms::Button());
			this->Ex3 = (gcnew System::Windows::Forms::Button());
			this->Ex2 = (gcnew System::Windows::Forms::Button());
			this->Ex5 = (gcnew System::Windows::Forms::Button());
			this->kaka = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserRoutesBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserSchedBG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserTrainsBG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seatSelectBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seatss))->BeginInit();
			this->SuspendLayout();
			// 
			// UserRoutes
			// 
			this->UserRoutes->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserRoutes.BackgroundImage")));
			this->UserRoutes->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserRoutes->FlatAppearance->BorderSize = 0;
			this->UserRoutes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UserRoutes->Location = System::Drawing::Point(149, 286);
			this->UserRoutes->Name = L"UserRoutes";
			this->UserRoutes->Size = System::Drawing::Size(424, 212);
			this->UserRoutes->TabIndex = 0;
			this->UserRoutes->UseVisualStyleBackColor = true;
			this->UserRoutes->Click += gcnew System::EventHandler(this, &MHM_User::UserRoutes_Click);
			// 
			// UserRoutesBg
			// 
			this->UserRoutesBg->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserRoutesBg.BackgroundImage")));
			this->UserRoutesBg->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserRoutesBg->Location = System::Drawing::Point(602, 162);
			this->UserRoutesBg->Name = L"UserRoutesBg";
			this->UserRoutesBg->Size = System::Drawing::Size(700, 600);
			this->UserRoutesBg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->UserRoutesBg->TabIndex = 1;
			this->UserRoutesBg->TabStop = false;
			this->UserRoutesBg->Visible = false;
			// 
			// ContinueU1
			// 
			this->ContinueU1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContinueU1.BackgroundImage")));
			this->ContinueU1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ContinueU1->FlatAppearance->BorderSize = 0;
			this->ContinueU1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContinueU1->Location = System::Drawing::Point(829, 637);
			this->ContinueU1->Name = L"ContinueU1";
			this->ContinueU1->Size = System::Drawing::Size(261, 94);
			this->ContinueU1->TabIndex = 2;
			this->ContinueU1->UseVisualStyleBackColor = true;
			this->ContinueU1->Visible = false;
			this->ContinueU1->Click += gcnew System::EventHandler(this, &MHM_User::ContinueU1_Click);
			// 
			// UserRoutesList
			// 
			this->UserRoutesList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UserRoutesList->CheckOnClick = true;
			this->UserRoutesList->FormattingEnabled = true;
			this->UserRoutesList->Location = System::Drawing::Point(687, 305);
			this->UserRoutesList->Name = L"UserRoutesList";
			this->UserRoutesList->ScrollAlwaysVisible = true;
			this->UserRoutesList->Size = System::Drawing::Size(575, 299);
			this->UserRoutesList->TabIndex = 3;
			this->UserRoutesList->Visible = false;
			// 
			// UserSchedule
			// 
			this->UserSchedule->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserSchedule.BackgroundImage")));
			this->UserSchedule->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserSchedule->FlatAppearance->BorderSize = 0;
			this->UserSchedule->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UserSchedule->Location = System::Drawing::Point(714, 286);
			this->UserSchedule->Name = L"UserSchedule";
			this->UserSchedule->Size = System::Drawing::Size(424, 212);
			this->UserSchedule->TabIndex = 4;
			this->UserSchedule->UseVisualStyleBackColor = true;
			this->UserSchedule->Visible = false;
			this->UserSchedule->Click += gcnew System::EventHandler(this, &MHM_User::UserSchedule_Click);
			// 
			// UserSchedBG
			// 
			this->UserSchedBG->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserSchedBG.BackgroundImage")));
			this->UserSchedBG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserSchedBG->Location = System::Drawing::Point(602, 162);
			this->UserSchedBG->Name = L"UserSchedBG";
			this->UserSchedBG->Size = System::Drawing::Size(700, 600);
			this->UserSchedBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->UserSchedBG->TabIndex = 5;
			this->UserSchedBG->TabStop = false;
			this->UserSchedBG->Visible = false;
			// 
			// ContinueU2
			// 
			this->ContinueU2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContinueU2.BackgroundImage")));
			this->ContinueU2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ContinueU2->FlatAppearance->BorderSize = 0;
			this->ContinueU2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContinueU2->Location = System::Drawing::Point(829, 637);
			this->ContinueU2->Name = L"ContinueU2";
			this->ContinueU2->Size = System::Drawing::Size(261, 94);
			this->ContinueU2->TabIndex = 6;
			this->ContinueU2->UseVisualStyleBackColor = true;
			this->ContinueU2->Visible = false;
			this->ContinueU2->Click += gcnew System::EventHandler(this, &MHM_User::ContinueU2_Click);
			// 
			// UserScheduleList
			// 
			this->UserScheduleList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UserScheduleList->CheckOnClick = true;
			this->UserScheduleList->FormattingEnabled = true;
			this->UserScheduleList->Location = System::Drawing::Point(670, 299);
			this->UserScheduleList->Name = L"UserScheduleList";
			this->UserScheduleList->ScrollAlwaysVisible = true;
			this->UserScheduleList->Size = System::Drawing::Size(562, 322);
			this->UserScheduleList->TabIndex = 7;
			this->UserScheduleList->Visible = false;
			// 
			// UserTrains
			// 
			this->UserTrains->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserTrains.BackgroundImage")));
			this->UserTrains->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserTrains->FlatAppearance->BorderSize = 0;
			this->UserTrains->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UserTrains->Location = System::Drawing::Point(1267, 286);
			this->UserTrains->Name = L"UserTrains";
			this->UserTrains->Size = System::Drawing::Size(424, 212);
			this->UserTrains->TabIndex = 8;
			this->UserTrains->UseVisualStyleBackColor = true;
			this->UserTrains->Visible = false;
			this->UserTrains->Click += gcnew System::EventHandler(this, &MHM_User::UserTrains_Click);
			// 
			// UserTrainsBG
			// 
			this->UserTrainsBG->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserTrainsBG.BackgroundImage")));
			this->UserTrainsBG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserTrainsBG->Location = System::Drawing::Point(602, 162);
			this->UserTrainsBG->Name = L"UserTrainsBG";
			this->UserTrainsBG->Size = System::Drawing::Size(700, 600);
			this->UserTrainsBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->UserTrainsBG->TabIndex = 9;
			this->UserTrainsBG->TabStop = false;
			this->UserTrainsBG->Visible = false;
			// 
			// ContinueU3
			// 
			this->ContinueU3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContinueU3.BackgroundImage")));
			this->ContinueU3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ContinueU3->FlatAppearance->BorderSize = 0;
			this->ContinueU3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContinueU3->Location = System::Drawing::Point(829, 637);
			this->ContinueU3->Name = L"ContinueU3";
			this->ContinueU3->Size = System::Drawing::Size(261, 94);
			this->ContinueU3->TabIndex = 10;
			this->ContinueU3->UseVisualStyleBackColor = true;
			this->ContinueU3->Visible = false;
			this->ContinueU3->Click += gcnew System::EventHandler(this, &MHM_User::ContinueU3_Click);
			// 
			// UserTrainList
			// 
			this->UserTrainList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UserTrainList->CheckOnClick = true;
			this->UserTrainList->FormattingEnabled = true;
			this->UserTrainList->Location = System::Drawing::Point(661, 295);
			this->UserTrainList->Name = L"UserTrainList";
			this->UserTrainList->ScrollAlwaysVisible = true;
			this->UserTrainList->Size = System::Drawing::Size(600, 299);
			this->UserTrainList->TabIndex = 11;
			this->UserTrainList->Visible = false;
			// 
			// UserSelectsSeats
			// 
			this->UserSelectsSeats->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UserSelectsSeats.BackgroundImage")));
			this->UserSelectsSeats->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->UserSelectsSeats->FlatAppearance->BorderSize = 0;
			this->UserSelectsSeats->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UserSelectsSeats->Location = System::Drawing::Point(714, 665);
			this->UserSelectsSeats->Name = L"UserSelectsSeats";
			this->UserSelectsSeats->Size = System::Drawing::Size(424, 212);
			this->UserSelectsSeats->TabIndex = 12;
			this->UserSelectsSeats->UseVisualStyleBackColor = true;
			this->UserSelectsSeats->Visible = false;
			this->UserSelectsSeats->Click += gcnew System::EventHandler(this, &MHM_User::UserSelectsSeats_Click);
			// 
			// seatSelectBg
			// 
			this->seatSelectBg->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"seatSelectBg.BackgroundImage")));
			this->seatSelectBg->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->seatSelectBg->Location = System::Drawing::Point(602, 162);
			this->seatSelectBg->Name = L"seatSelectBg";
			this->seatSelectBg->Size = System::Drawing::Size(700, 600);
			this->seatSelectBg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->seatSelectBg->TabIndex = 13;
			this->seatSelectBg->TabStop = false;
			this->seatSelectBg->Visible = false;
			// 
			// seatss
			// 
			this->seatss->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"seatss.Image")));
			this->seatss->Location = System::Drawing::Point(640, 272);
			this->seatss->Name = L"seatss";
			this->seatss->Size = System::Drawing::Size(627, 365);
			this->seatss->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->seatss->TabIndex = 14;
			this->seatss->TabStop = false;
			this->seatss->Visible = false;
			// 
			// ContinueU4
			// 
			this->ContinueU4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContinueU4.BackgroundImage")));
			this->ContinueU4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ContinueU4->FlatAppearance->BorderSize = 0;
			this->ContinueU4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContinueU4->Location = System::Drawing::Point(799, 654);
			this->ContinueU4->Name = L"ContinueU4";
			this->ContinueU4->Size = System::Drawing::Size(309, 87);
			this->ContinueU4->TabIndex = 15;
			this->ContinueU4->UseVisualStyleBackColor = true;
			this->ContinueU4->Visible = false;
			this->ContinueU4->Click += gcnew System::EventHandler(this, &MHM_User::ContinueU4_Click);
			// 
			// B1
			// 
			this->B1->Location = System::Drawing::Point(664, 295);
			this->B1->Name = L"B1";
			this->B1->Size = System::Drawing::Size(89, 63);
			this->B1->TabIndex = 16;
			this->B1->Text = L"Business";
			this->B1->UseVisualStyleBackColor = true;
			this->B1->Visible = false;
			this->B1->Click += gcnew System::EventHandler(this, &MHM_User::B1_Click);
			// 
			// B2
			// 
			this->B2->Location = System::Drawing::Point(768, 295);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(89, 63);
			this->B2->TabIndex = 17;
			this->B2->Text = L"Business";
			this->B2->UseVisualStyleBackColor = true;
			this->B2->Visible = false;
			this->B2->Click += gcnew System::EventHandler(this, &MHM_User::B2_Click);
			// 
			// Ec1
			// 
			this->Ec1->Location = System::Drawing::Point(665, 546);
			this->Ec1->Name = L"Ec1";
			this->Ec1->Size = System::Drawing::Size(89, 63);
			this->Ec1->TabIndex = 18;
			this->Ec1->Text = L"Economic";
			this->Ec1->UseVisualStyleBackColor = true;
			this->Ec1->Visible = false;
			this->Ec1->Click += gcnew System::EventHandler(this, &MHM_User::Ec1_Click);
			// 
			// Ec4
			// 
			this->Ec4->Location = System::Drawing::Point(1145, 551);
			this->Ec4->Name = L"Ec4";
			this->Ec4->Size = System::Drawing::Size(89, 63);
			this->Ec4->TabIndex = 19;
			this->Ec4->Text = L"Economic";
			this->Ec4->UseVisualStyleBackColor = true;
			this->Ec4->Visible = false;
			this->Ec4->Click += gcnew System::EventHandler(this, &MHM_User::Ec4_Click);
			// 
			// B4
			// 
			this->B4->Location = System::Drawing::Point(1146, 300);
			this->B4->Name = L"B4";
			this->B4->Size = System::Drawing::Size(89, 63);
			this->B4->TabIndex = 20;
			this->B4->Text = L"Business";
			this->B4->UseVisualStyleBackColor = true;
			this->B4->Visible = false;
			this->B4->Click += gcnew System::EventHandler(this, &MHM_User::B4_Click);
			// 
			// B3
			// 
			this->B3->Location = System::Drawing::Point(1044, 300);
			this->B3->Name = L"B3";
			this->B3->Size = System::Drawing::Size(89, 63);
			this->B3->TabIndex = 21;
			this->B3->Text = L"Business";
			this->B3->UseVisualStyleBackColor = true;
			this->B3->Visible = false;
			this->B3->Click += gcnew System::EventHandler(this, &MHM_User::B3_Click);
			// 
			// Ec3
			// 
			this->Ec3->Location = System::Drawing::Point(1043, 551);
			this->Ec3->Name = L"Ec3";
			this->Ec3->Size = System::Drawing::Size(89, 63);
			this->Ec3->TabIndex = 22;
			this->Ec3->Text = L"Economic";
			this->Ec3->UseVisualStyleBackColor = true;
			this->Ec3->Visible = false;
			this->Ec3->Click += gcnew System::EventHandler(this, &MHM_User::Ec3_Click);
			// 
			// Ec2
			// 
			this->Ec2->Location = System::Drawing::Point(766, 546);
			this->Ec2->Name = L"Ec2";
			this->Ec2->Size = System::Drawing::Size(89, 63);
			this->Ec2->TabIndex = 23;
			this->Ec2->Text = L"Economic";
			this->Ec2->UseVisualStyleBackColor = true;
			this->Ec2->Visible = false;
			this->Ec2->Click += gcnew System::EventHandler(this, &MHM_User::Ec2_Click);
			// 
			// Ex1
			// 
			this->Ex1->Location = System::Drawing::Point(666, 372);
			this->Ex1->Name = L"Ex1";
			this->Ex1->Size = System::Drawing::Size(89, 63);
			this->Ex1->TabIndex = 24;
			this->Ex1->Text = L"Executive";
			this->Ex1->UseVisualStyleBackColor = true;
			this->Ex1->Visible = false;
			this->Ex1->Click += gcnew System::EventHandler(this, &MHM_User::Ex1_Click);
			// 
			// Ex6
			// 
			this->Ex6->Location = System::Drawing::Point(766, 467);
			this->Ex6->Name = L"Ex6";
			this->Ex6->Size = System::Drawing::Size(89, 63);
			this->Ex6->TabIndex = 25;
			this->Ex6->Text = L"Executive";
			this->Ex6->UseVisualStyleBackColor = true;
			this->Ex6->Visible = false;
			this->Ex6->Click += gcnew System::EventHandler(this, &MHM_User::Ex6_Click);
			// 
			// Ex7
			// 
			this->Ex7->Location = System::Drawing::Point(1043, 473);
			this->Ex7->Name = L"Ex7";
			this->Ex7->Size = System::Drawing::Size(89, 63);
			this->Ex7->TabIndex = 26;
			this->Ex7->Text = L"Executive";
			this->Ex7->UseVisualStyleBackColor = true;
			this->Ex7->Visible = false;
			this->Ex7->Click += gcnew System::EventHandler(this, &MHM_User::Ex7_Click);
			// 
			// Ex8
			// 
			this->Ex8->Location = System::Drawing::Point(1146, 473);
			this->Ex8->Name = L"Ex8";
			this->Ex8->Size = System::Drawing::Size(89, 63);
			this->Ex8->TabIndex = 27;
			this->Ex8->Text = L"Executive";
			this->Ex8->UseVisualStyleBackColor = true;
			this->Ex8->Visible = false;
			this->Ex8->Click += gcnew System::EventHandler(this, &MHM_User::Ex8_Click);
			// 
			// Ex4
			// 
			this->Ex4->Location = System::Drawing::Point(1145, 378);
			this->Ex4->Name = L"Ex4";
			this->Ex4->Size = System::Drawing::Size(89, 63);
			this->Ex4->TabIndex = 28;
			this->Ex4->Text = L"Executive";
			this->Ex4->UseVisualStyleBackColor = true;
			this->Ex4->Visible = false;
			this->Ex4->Click += gcnew System::EventHandler(this, &MHM_User::Ex4_Click);
			// 
			// Ex3
			// 
			this->Ex3->Location = System::Drawing::Point(1045, 377);
			this->Ex3->Name = L"Ex3";
			this->Ex3->Size = System::Drawing::Size(89, 63);
			this->Ex3->TabIndex = 29;
			this->Ex3->Text = L"Executive";
			this->Ex3->UseVisualStyleBackColor = true;
			this->Ex3->Visible = false;
			this->Ex3->Click += gcnew System::EventHandler(this, &MHM_User::Ex3_Click);
			// 
			// Ex2
			// 
			this->Ex2->Location = System::Drawing::Point(767, 373);
			this->Ex2->Name = L"Ex2";
			this->Ex2->Size = System::Drawing::Size(89, 63);
			this->Ex2->TabIndex = 30;
			this->Ex2->Text = L"Executive";
			this->Ex2->UseVisualStyleBackColor = true;
			this->Ex2->Visible = false;
			this->Ex2->Click += gcnew System::EventHandler(this, &MHM_User::Ex2_Click);
			// 
			// Ex5
			// 
			this->Ex5->Location = System::Drawing::Point(663, 467);
			this->Ex5->Name = L"Ex5";
			this->Ex5->Size = System::Drawing::Size(89, 63);
			this->Ex5->TabIndex = 31;
			this->Ex5->Text = L"Executive";
			this->Ex5->UseVisualStyleBackColor = true;
			this->Ex5->Visible = false;
			this->Ex5->Click += gcnew System::EventHandler(this, &MHM_User::Ex5_Click);
			// 
			// kaka
			// 
			this->kaka->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->kaka->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kaka.BackgroundImage")));
			this->kaka->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->kaka->FlatAppearance->BorderSize = 0;
			this->kaka->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->kaka->Location = System::Drawing::Point(1585, 914);
			this->kaka->Name = L"kaka";
			this->kaka->Size = System::Drawing::Size(187, 138);
			this->kaka->TabIndex = 32;
			this->kaka->UseVisualStyleBackColor = false;
			this->kaka->Visible = false;
			this->kaka->Click += gcnew System::EventHandler(this, &MHM_User::kaka_Click);
			// 
			// MHM_User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1883, 1050);
			this->Controls->Add(this->kaka);
			this->Controls->Add(this->Ex5);
			this->Controls->Add(this->Ex2);
			this->Controls->Add(this->Ex3);
			this->Controls->Add(this->Ex4);
			this->Controls->Add(this->Ex8);
			this->Controls->Add(this->Ex7);
			this->Controls->Add(this->Ex6);
			this->Controls->Add(this->Ex1);
			this->Controls->Add(this->Ec2);
			this->Controls->Add(this->Ec3);
			this->Controls->Add(this->B3);
			this->Controls->Add(this->B4);
			this->Controls->Add(this->Ec4);
			this->Controls->Add(this->Ec1);
			this->Controls->Add(this->B2);
			this->Controls->Add(this->B1);
			this->Controls->Add(this->ContinueU4);
			this->Controls->Add(this->seatss);
			this->Controls->Add(this->seatSelectBg);
			this->Controls->Add(this->UserTrainList);
			this->Controls->Add(this->ContinueU3);
			this->Controls->Add(this->UserTrainsBG);
			this->Controls->Add(this->UserScheduleList);
			this->Controls->Add(this->ContinueU2);
			this->Controls->Add(this->UserSchedBG);
			this->Controls->Add(this->UserRoutesList);
			this->Controls->Add(this->ContinueU1);
			this->Controls->Add(this->UserRoutesBg);
			this->Controls->Add(this->UserRoutes);
			this->Controls->Add(this->UserSchedule);
			this->Controls->Add(this->UserTrains);
			this->Controls->Add(this->UserSelectsSeats);
			this->DoubleBuffered = true;
			this->Name = L"MHM_User";
			this->Text = L"MHM_User";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserRoutesBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserSchedBG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserTrainsBG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seatSelectBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seatss))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");
	private: System::Void UserRoutes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->UserRoutesList->Visible = true;
		this->ContinueU1->Visible = true;
		this->UserRoutesBg->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->UserRoutes->Visible = false;
		this->UserSchedule->Visible = false;
	}

	private: System::Void UserRoutesList_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
	{
		// Uncheck all other items if the current item is being checked
		if (e->CurrentValue == CheckState::Unchecked && e->NewValue == CheckState::Checked)
		{
			for (int i = 0; i < UserRoutesList->Items->Count; i++)
			{
				if (i != e->Index)
				{
					UserRoutesList->SetItemChecked(i, false);
				}
			}
		}
	}

	private: System::Void ContinueU1_Click(System::Object^ sender, System::EventArgs^ e)
	{

		US.UserRouteSetter("");
		
		for (int i = 0; i < this->UserRoutesList->Items->Count; i++)
		{
			if (this->UserRoutesList->GetItemChecked(i))
			{
				String^ checkedItemText = dynamic_cast<String^>(this->UserRoutesList->Items[i]);
				string rt = msclr::interop::marshal_as<std::string>(checkedItemText);
				US.UserRouteSetter(rt);
			}
		}

		if (US.UserRouteGetter() != "")
		{
			this->UserRoutes->Visible = true;
			this->UserSchedule->Visible = true;
			this->UserRoutesList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG2.png");
			this->ContinueU1->Visible = false;
			this->UserRoutesBg->Visible = false;
		}
		else
		{
			this->UserRoutes->Visible = true;
			this->UserRoutesList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG1.png");
			this->ContinueU1->Visible = false;
			this->UserRoutesBg->Visible = false;
			this->UserSchedule->Visible = false;
		}

		//Available ScheduleListBox Data/dynamically displaying the database's info
		//getting index of the route that user selected
		for (int i = 0; i < rowCount; i++)
		{
			if (US.UserRouteGetter() == (b[i].startUserGetter() + " to " + b[i].endUserGetter()))
			{
				index = i;
				break;
			}
		}

		for (int j = 0; j < 24; j++)
		{
			// Adds available option to schedulesListbox
			if (b[index].scheduleUserGetter()[j] == 1)
			{
				String^ itemText = gcnew String(j + 1 + ":00");
				UserScheduleList->Items->Add(itemText);
			}
		}

		//Available TrainListBox Data/dynamically displaying the database's info
		for (int j = 0; j < 3; j++)
		{
			// Adds available option to schedulesListbox
			if (b[index].trainsUserGetter()[j] == 1)
			{
				if (j == 0)
				{
					String^ itemText = gcnew String("Green Line");
					UserTrainList->Items->Add(itemText);
				}
				else if (j == 1)
				{
					String^ itemText = gcnew String("Hazara Express");
					UserTrainList->Items->Add(itemText);
				}
				else if(j == 2)
				{
					String^ itemText = gcnew String("Chiltan Express");
					UserTrainList->Items->Add(itemText);
				}
			}
		}
	}
	
	private: System::Void UserSchedule_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->ContinueU2->Visible = true;
		this->UserScheduleList->Visible = true;
		this->UserSchedBG->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->UserRoutes->Visible = false;
		this->UserSchedule->Visible = false;
	}

	private: System::Void UserScheduleList_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
	{
		// Uncheck all other items if the current item is being checked
		if (e->CurrentValue == CheckState::Unchecked && e->NewValue == CheckState::Checked)
		{
			for (int i = 0; i < UserScheduleList->Items->Count; i++)
			{
				if (i != e->Index)
				{
					UserScheduleList->SetItemChecked(i, false);
				}
			}
		}
	}

	private: System::Void ContinueU2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		US.UserScheduleSetter(0);

		for (int i = 0; i < this->UserScheduleList->Items->Count; i++)
		{
			if (this->UserScheduleList->GetItemChecked(i))
			{
				String^ checkedItemText = dynamic_cast<String^>(this->UserScheduleList->Items[i]);
				string sd = msclr::interop::marshal_as<std::string>(checkedItemText);
				string scd;
				for (int j = 0; sd[j] != ':'; j++)
				{
					scd = scd + sd[j];
				}
				US.UserScheduleSetter(stoi(scd));
			}
		}

		if (US.UserScheduleGetter() != 0)
		{
			this->UserRoutes->Visible = true;
			this->UserSchedule->Visible = true;
			this->UserTrains->Visible = true;
			this->UserScheduleList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG3.png");
			this->ContinueU2->Visible = false;
			this->UserSchedBG->Visible = false;
		}
		else
		{
			this->UserRoutes->Visible = true;
			this->UserSchedule->Visible = true;
			this->UserScheduleList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG2.png");
			this->UserTrains->Visible = false;
			this->ContinueU2->Visible = false;
			this->UserSchedBG->Visible = false;
		}

	}

	private: System::Void UserTrains_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->ContinueU3->Visible = true;
		this->UserTrainList->Visible = true;
		this->UserTrainsBG->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->UserRoutes->Visible = false;
		this->UserSchedule->Visible = false;
		this->UserTrains->Visible = false;
	}

	private: System::Void UserTrainList_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
	{
		// Uncheck all other items if the current item is being checked
		if (e->CurrentValue == CheckState::Unchecked && e->NewValue == CheckState::Checked)
		{
			for (int i = 0; i < UserTrainList->Items->Count; i++)
			{
				if (i != e->Index)
				{
					UserTrainList->SetItemChecked(i, false);
				}
			}
		}
	}
	
	private: System::Void ContinueU3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		US.UserTrainSetter(-1);

		for (int i = 0; i < this->UserTrainList->Items->Count; i++)
		{
			if (this->UserTrainList->GetItemChecked(i))
			{
				String^ checkedItemText = dynamic_cast<String^>(this->UserTrainList->Items[i]);
				string t = msclr::interop::marshal_as<std::string>(checkedItemText);
				int x = 0;
				if (t == "Green Line")
				{
					x = 0;
				}
				else if (t == "Hazara Express")
				{
					x = 1;
				}
				else if (t == "Chiltan Express")
				{
					x = 2;
				}
				US.UserTrainSetter(x);
			}
		}

		if (US.UserTrainGetter() != -1)
		{
			this->UserRoutes->Visible = true;
			this->UserSchedule->Visible = true;
			this->UserTrains->Visible = true;
			this->UserSelectsSeats->Visible = true;
			this->UserTrainList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG4.png");
			this->ContinueU3->Visible = false;
			this->UserTrainsBG->Visible = false;
		}
		else
		{
			this->UserRoutes->Visible = true;
			this->UserSchedule->Visible = true;
			this->UserTrains->Visible = true;
			this->UserSelectsSeats->Visible = false;
			this->UserTrainList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG3.png");
			this->ContinueU3->Visible = false;
			this->UserTrainsBG->Visible = false;
		}
	}

	private: System::Void UserSelectsSeats_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->B1->Visible = true;
		this->B2->Visible = true;
		this->B3->Visible = true;
		this->B4->Visible = true;
		this->Ex1->Visible = true;
		this->Ex2->Visible = true;
		this->Ex3->Visible = true;
		this->Ex4->Visible = true;
		this->Ex5->Visible = true;
		this->Ex6->Visible = true;
		this->Ex7->Visible = true;
		this->Ex8->Visible = true;
		this->Ec1->Visible = true;
		this->Ec2->Visible = true;
		this->Ec3->Visible = true;
		this->Ec4->Visible = true;
		this->ContinueU4->Visible = true;
		this->seatss->Visible = true;
		this->seatSelectBg->Visible = true;
	}

	private: System::Void B1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->B1->Visible = false;
		US.no_of_Business_seatsSetter(US.no_of_Business_seatsGetter() + 1);
	}
	private: System::Void B2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->B2->Visible = false;
		US.no_of_Business_seatsSetter(US.no_of_Business_seatsGetter() + 1);
	}
	private: System::Void B3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->B3->Visible = false;
		US.no_of_Business_seatsSetter(US.no_of_Business_seatsGetter() + 1);
	}
	private: System::Void B4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->B4->Visible = false;
		US.no_of_Business_seatsSetter(US.no_of_Business_seatsGetter() + 1);
	}
	private: System::Void Ex1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex1->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex2->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex3->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex4->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex5->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex6->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex7->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ex8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ex8->Visible = false;
		US.no_of_Economic_seatsSetter(US.no_of_Economic_seatsGetter() + 1);
	}
	private: System::Void Ec1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ec1->Visible = false;
		US.no_of_Executive_seatsSetter(US.no_of_Executive_seatsGetter() + 1);
	}
	private: System::Void Ec2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ec2->Visible = false;
		US.no_of_Executive_seatsSetter(US.no_of_Executive_seatsGetter() + 1);
	}
	private: System::Void Ec3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ec3->Visible = false;
		US.no_of_Executive_seatsSetter(US.no_of_Executive_seatsGetter() + 1);
	}
	private: System::Void Ec4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Ec4->Visible = false;
		US.no_of_Executive_seatsSetter(US.no_of_Executive_seatsGetter() + 1);
	}
	
	private: System::Void ContinueU4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->kaka->Visible = true;
		this->B1->Visible = false;
		this->B2->Visible = false;
		this->B3->Visible = false;
		this->B4->Visible = false;
		this->Ex1->Visible = false;
		this->Ex2->Visible = false;
		this->Ex3->Visible = false;
		this->Ex4->Visible = false;
		this->Ex5->Visible = false;
		this->Ex6->Visible = false;
		this->Ex7->Visible = false;
		this->Ex8->Visible = false;
		this->Ec1->Visible = false;
		this->Ec2->Visible = false;
		this->Ec3->Visible = false;
		this->Ec4->Visible = false;
		SoundPlayer^ player = gcnew SoundPlayer("Assets\\paparapapa.wav");
		player->Play();
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG5.png");
		this->ContinueU4->Visible = false;
		this->seatss->Visible = false;
		this->seatSelectBg->Visible = false;
	}

	private: System::Void kaka_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		MHMUser::MHM_Payment a(US);
		this->Close();
	}
};
}

#endif