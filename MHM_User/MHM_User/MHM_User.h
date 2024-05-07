#ifndef USER_SELECTION_H
#define USER_SELECTION_H
#include"MHM_User_Functions.h"

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserRoutesBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserSchedBG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserTrainsBG))->BeginInit();
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
			// MHM_User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1418, 968);
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
			this->DoubleBuffered = true;
			this->Name = L"MHM_User";
			this->Text = L"MHM_User";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserRoutesBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserSchedBG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UserTrainsBG))->EndInit();
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
			//new button true
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
			//new button false
			this->UserTrainList->Visible = false;
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\RawBG3.png");
			this->ContinueU3->Visible = false;
			this->UserTrainsBG->Visible = false;
		}
	}
};
}

#endif