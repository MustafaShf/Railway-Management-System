#ifndef Admin_H
#define Admin_H

#include"MHM_Functions.h"

dataRetriever* a;
Admin admin;
int rowCount = 0;
int feedbacks = 0;
int index = 0;
int index1 = 0;

namespace MHMTMSV21
{

	/// <summary>
	/// Summary for MHM_Admin0
	/// </summary>
	public ref class MHM_Admin0 : public System::Windows::Forms::Form
	{
	public:
		MHM_Admin0(void)
		{
			//-------------------------------------INITIALIZE AND EARLY STUFF ETC----------------------------------
			InitializeComponent();
			routes->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;

			//conecting to the database and getting the data
			rowCount = admin.GetData(a, admin);
			feedbacks = admin.viewFeedback(a);

			//RouteListBox Data/dynamically displaying the database's info
			int i = 0;
			while (i < rowCount)
			{
				int checkboxState = a[i].availabilityGetter();

				String^ itemText = gcnew String((a[i].startGetter() + " to " + a[i].endGetter()).c_str());

				// Adds option to routesbox
				routes->Items->Add(itemText);

				//Sets the checked state based on availability from the database
				routes->SetItemChecked(routes->Items->Count - 1, checkboxState);
				i++;
			}

			//Schedule routes/ makes as many buttons as there are roots, then makes different events for each button
			for (i = 0; i < rowCount; i++)
			{
				System::Windows::Forms::Button^ button = gcnew System::Windows::Forms::Button();
				button->Text = gcnew String((a[i].startGetter() + " to " + a[i].endGetter()).c_str());
				button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)), static_cast<System::Int32>(static_cast<System::Byte>(83)),
					static_cast<System::Int32>(static_cast<System::Byte>(207)));
				button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				button->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				button->Size = System::Drawing::Size(178, 44);
				button->Name = "ScheduleRoute"+ i;

				button->Click += gcnew System::EventHandler(this, &MHM_Admin0::Button_Click); // Attach event handler
				ScheduleRoutesBox->Controls->Add(button); // Add button to the FlowLayoutPanel
			}

			//Trains on routes/ makes as many buttons as there are roots, then makes different events for each button
			for (i = 0; i < rowCount; i++)
			{
				System::Windows::Forms::Button^ button1 = gcnew System::Windows::Forms::Button();
				button1->Text = gcnew String((a[i].startGetter() + " to " + a[i].endGetter()).c_str());
				button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)), static_cast<System::Int32>(static_cast<System::Byte>(83)),
					static_cast<System::Int32>(static_cast<System::Byte>(207)));
				button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				button1->Size = System::Drawing::Size(178, 44);
				button1->Name = "TrainRoute" + i;

				button1->Click += gcnew System::EventHandler(this, &MHM_Admin0::TrainRoute_Button_Click); // Attach event handler
				TrainsBox->Controls->Add(button1); // Add button to the FlowLayoutPanel
			}
		}

		//------------------------------------A	BUTTON ON THE SCHEDULE ROUTES IS CLICKED------------------------------
		void Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Windows::Forms::Button^ clickedButton = dynamic_cast<System::Windows::Forms::Button^>(sender);
			if (clickedButton != nullptr)
			{
				// Perform actions based on which button was clicked
				System::String^ buttonName = clickedButton->Name;
				for (int i = 0; i < rowCount; i++)
				{
					if (buttonName == "ScheduleRoute"+i)	//buttons are names in order and loop is controlled through that
					{
						index = i;
						int j = 0;
						while (j < 24)
						{
							int checkboxState = a[i].scheduleGetter()[j];	//checks 0 or 1

							String^ itemText = gcnew String(j + 1 + ":00");

							// Adds option to Hours checkbox
							Hours->Items->Add(itemText);

							//Sets the checked state based on schedule from the database
							Hours->SetItemChecked(Hours->Items->Count - 1, checkboxState);
							j++;
						}
						this->ScheduleListContinue->Visible = true;
						this->Hours->Visible = true;
						this->Continue2->Visible = false;
					}
				}

			}
		}

		//------------------------------------A	BUTTON ON THE TRAIN ROUTES IS CLICKED------------------------------
		void TrainRoute_Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Windows::Forms::Button^ clickedButton = dynamic_cast<System::Windows::Forms::Button^>(sender);
			if (clickedButton != nullptr)
			{
				// Perform actions based on which button was clicked
				System::String^ buttonName = clickedButton->Name;
				for (int i = 0; i < rowCount; i++)
				{
					if (buttonName == "TrainRoute" + i)	//buttons are names in order and loop is controlled through that
					{
						index1 = i;
						int j = 0;
						while (j < 3)
						{
							int checkboxState = a[i].trainsGetter()[j];	//checks 0 or 1
							String^ itemText;

							if (j == 0)
							{
								itemText = gcnew String("Green Line");
							}
							else if (j == 1)
							{
								itemText = gcnew String("Hazara Express");
							}
							else if (j == 2)
							{
								itemText = gcnew String("Chiltan Express");
							}

							// Adds option to Hours checkbox
							TrainsList->Items->Add(itemText);

							//Sets the checked state based on schedule from the database
							TrainsList->SetItemChecked(TrainsList->Items->Count - 1, checkboxState);
							j++;
						}
						this->TrainListContinue->Visible = true;
						this->TrainsList->Visible = true;
						this->Continue5->Visible = false;
					}
				}

			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		//----------------------------------Destructor/Delete all pointers etc.-----------------------------------
		~MHM_Admin0()
		{
			if (components)
			{
				delete components;
			}
		}

	//-----------------------------All buttons/components on the form declared------------------------------------
	private: System::Windows::Forms::Button^ routesButton;
	private: System::Windows::Forms::CheckedListBox^ routes;
	private: System::Windows::Forms::Button^ Continue1;
	private: System::Windows::Forms::PictureBox^ RouteListBox;
	private: System::Windows::Forms::Button^ schedulesButton;
	private: System::Windows::Forms::PictureBox^ schedulesBox;
	private: System::Windows::Forms::Button^ Continue2;
	private: System::Windows::Forms::Button^ priceSetter;
	private: System::Windows::Forms::Button^ Continue3;
	private: System::Windows::Forms::PictureBox^ fareBG;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ ReadFeedback;
	private: System::Windows::Forms::Button^ Continue4;
	private: System::Windows::Forms::PictureBox^ FeedbackBG;
	private: System::Windows::Forms::Label^ FBseatNoLabel;
	private: System::Windows::Forms::Label^ FeedbackLabel;
	private: System::Windows::Forms::Label^ RatingLabel;
	private: System::Windows::Forms::TextBox^ FBSeatNo;
	private: System::Windows::Forms::TextBox^ Feedback;
	private: System::Windows::Forms::TextBox^ Rating;
	private: System::Windows::Forms::Button^ NextFeedback;

private: System::Windows::Forms::Button^ ScheduleListContinue;
	private: System::Windows::Forms::FlowLayoutPanel^ ScheduleRoutesBox;
private: System::Windows::Forms::CheckedListBox^ Hours;
private: System::Windows::Forms::PictureBox^ TrainsBG;

private: System::Windows::Forms::Button^ trainsButton;
private: System::Windows::Forms::Button^ Continue5;
private: System::Windows::Forms::FlowLayoutPanel^ TrainsBox;
private: System::Windows::Forms::CheckedListBox^ TrainsList;
private: System::Windows::Forms::Button^ TrainListContinue;
private: System::Windows::Forms::Button^ Finish;

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
		//------------------------------------------EVERY COMPONENT ON DESIGN WINDOW'S CODE DETAILS-------------------
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MHM_Admin0::typeid));
			this->routesButton = (gcnew System::Windows::Forms::Button());
			this->routes = (gcnew System::Windows::Forms::CheckedListBox());
			this->Continue1 = (gcnew System::Windows::Forms::Button());
			this->RouteListBox = (gcnew System::Windows::Forms::PictureBox());
			this->schedulesButton = (gcnew System::Windows::Forms::Button());
			this->schedulesBox = (gcnew System::Windows::Forms::PictureBox());
			this->Continue2 = (gcnew System::Windows::Forms::Button());
			this->priceSetter = (gcnew System::Windows::Forms::Button());
			this->Continue3 = (gcnew System::Windows::Forms::Button());
			this->fareBG = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ReadFeedback = (gcnew System::Windows::Forms::Button());
			this->Continue4 = (gcnew System::Windows::Forms::Button());
			this->FeedbackBG = (gcnew System::Windows::Forms::PictureBox());
			this->FBseatNoLabel = (gcnew System::Windows::Forms::Label());
			this->FeedbackLabel = (gcnew System::Windows::Forms::Label());
			this->RatingLabel = (gcnew System::Windows::Forms::Label());
			this->FBSeatNo = (gcnew System::Windows::Forms::TextBox());
			this->Feedback = (gcnew System::Windows::Forms::TextBox());
			this->Rating = (gcnew System::Windows::Forms::TextBox());
			this->NextFeedback = (gcnew System::Windows::Forms::Button());
			this->ScheduleListContinue = (gcnew System::Windows::Forms::Button());
			this->ScheduleRoutesBox = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Hours = (gcnew System::Windows::Forms::CheckedListBox());
			this->TrainsBG = (gcnew System::Windows::Forms::PictureBox());
			this->trainsButton = (gcnew System::Windows::Forms::Button());
			this->Continue5 = (gcnew System::Windows::Forms::Button());
			this->TrainsBox = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->TrainsList = (gcnew System::Windows::Forms::CheckedListBox());
			this->TrainListContinue = (gcnew System::Windows::Forms::Button());
			this->Finish = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulesBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fareBG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FeedbackBG))->BeginInit();
			this->ScheduleRoutesBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrainsBG))->BeginInit();
			this->TrainsBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// routesButton
			// 
			this->routesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"routesButton.BackgroundImage")));
			this->routesButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->routesButton->FlatAppearance->BorderSize = 0;
			this->routesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->routesButton->Location = System::Drawing::Point(169, 228);
			this->routesButton->Name = L"routesButton";
			this->routesButton->Size = System::Drawing::Size(454, 242);
			this->routesButton->TabIndex = 0;
			this->routesButton->UseVisualStyleBackColor = true;
			this->routesButton->Click += gcnew System::EventHandler(this, &MHM_Admin0::routesButton_Click);
			// 
			// routes
			// 
			this->routes->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->routes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(177)), static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->routes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->routes->CheckOnClick = true;
			this->routes->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->routes->ForeColor = System::Drawing::SystemColors::Info;
			this->routes->FormattingEnabled = true;
			this->routes->Location = System::Drawing::Point(704, 275);
			this->routes->Name = L"routes";
			this->routes->ScrollAlwaysVisible = true;
			this->routes->Size = System::Drawing::Size(626, 322);
			this->routes->TabIndex = 1;
			this->routes->ThreeDCheckBoxes = true;
			this->routes->Visible = false;
			this->routes->SelectedIndexChanged += gcnew System::EventHandler(this, &MHM_Admin0::routes_SelectedIndexChanged);
			// 
			// Continue1
			// 
			this->Continue1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Continue1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Continue1.BackgroundImage")));
			this->Continue1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Continue1->FlatAppearance->BorderSize = 0;
			this->Continue1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue1->Font = (gcnew System::Drawing::Font(L"Arial Black", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continue1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Continue1->Location = System::Drawing::Point(759, 620);
			this->Continue1->Name = L"Continue1";
			this->Continue1->Size = System::Drawing::Size(324, 98);
			this->Continue1->TabIndex = 2;
			this->Continue1->UseVisualStyleBackColor = false;
			this->Continue1->Visible = false;
			this->Continue1->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue1_Click);
			// 
			// RouteListBox
			// 
			this->RouteListBox->BackColor = System::Drawing::Color::Transparent;
			this->RouteListBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->RouteListBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RouteListBox.Image")));
			this->RouteListBox->Location = System::Drawing::Point(530, 120);
			this->RouteListBox->Name = L"RouteListBox";
			this->RouteListBox->Size = System::Drawing::Size(806, 678);
			this->RouteListBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->RouteListBox->TabIndex = 3;
			this->RouteListBox->TabStop = false;
			this->RouteListBox->Visible = false;
			// 
			// schedulesButton
			// 
			this->schedulesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"schedulesButton.BackgroundImage")));
			this->schedulesButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->schedulesButton->FlatAppearance->BorderSize = 0;
			this->schedulesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->schedulesButton->Location = System::Drawing::Point(722, 228);
			this->schedulesButton->Name = L"schedulesButton";
			this->schedulesButton->Size = System::Drawing::Size(454, 242);
			this->schedulesButton->TabIndex = 4;
			this->schedulesButton->UseVisualStyleBackColor = true;
			this->schedulesButton->Click += gcnew System::EventHandler(this, &MHM_Admin0::schedulesButton_Click);
			// 
			// schedulesBox
			// 
			this->schedulesBox->BackColor = System::Drawing::Color::Transparent;
			this->schedulesBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->schedulesBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"schedulesBox.Image")));
			this->schedulesBox->Location = System::Drawing::Point(530, 120);
			this->schedulesBox->Name = L"schedulesBox";
			this->schedulesBox->Size = System::Drawing::Size(806, 678);
			this->schedulesBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->schedulesBox->TabIndex = 5;
			this->schedulesBox->TabStop = false;
			this->schedulesBox->Visible = false;
			// 
			// Continue2
			// 
			this->Continue2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Continue2.BackgroundImage")));
			this->Continue2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Continue2->FlatAppearance->BorderSize = 0;
			this->Continue2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue2->Location = System::Drawing::Point(772, 660);
			this->Continue2->Name = L"Continue2";
			this->Continue2->Size = System::Drawing::Size(324, 98);
			this->Continue2->TabIndex = 6;
			this->Continue2->UseVisualStyleBackColor = true;
			this->Continue2->Visible = false;
			this->Continue2->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue2_Click);
			// 
			// priceSetter
			// 
			this->priceSetter->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"priceSetter.BackgroundImage")));
			this->priceSetter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->priceSetter->FlatAppearance->BorderSize = 0;
			this->priceSetter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->priceSetter->Location = System::Drawing::Point(404, 530);
			this->priceSetter->Name = L"priceSetter";
			this->priceSetter->Size = System::Drawing::Size(452, 242);
			this->priceSetter->TabIndex = 7;
			this->priceSetter->UseVisualStyleBackColor = true;
			this->priceSetter->Click += gcnew System::EventHandler(this, &MHM_Admin0::priceSetter_Click);
			// 
			// Continue3
			// 
			this->Continue3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Continue3.BackgroundImage")));
			this->Continue3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Continue3->FlatAppearance->BorderSize = 0;
			this->Continue3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue3->Location = System::Drawing::Point(772, 641);
			this->Continue3->Name = L"Continue3";
			this->Continue3->Size = System::Drawing::Size(324, 98);
			this->Continue3->TabIndex = 8;
			this->Continue3->UseVisualStyleBackColor = true;
			this->Continue3->Visible = false;
			this->Continue3->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue3_Click);
			// 
			// fareBG
			// 
			this->fareBG->BackColor = System::Drawing::Color::Transparent;
			this->fareBG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->fareBG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fareBG.Image")));
			this->fareBG->Location = System::Drawing::Point(530, 120);
			this->fareBG->Name = L"fareBG";
			this->fareBG->Size = System::Drawing::Size(806, 678);
			this->fareBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->fareBG->TabIndex = 9;
			this->fareBG->TabStop = false;
			this->fareBG->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(585, 198);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(373, 46);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Current Route Price";
			this->label1->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(1117, 198);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(145, 53);
			this->textBox1->TabIndex = 11;
			this->textBox1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(587, 250);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(336, 46);
			this->label2->TabIndex = 12;
			this->label2->Text = L"*New Route Price";
			this->label2->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(1117, 250);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(145, 53);
			this->textBox2->TabIndex = 13;
			this->textBox2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(587, 302);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(526, 46);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Current Economic seat price";
			this->label3->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(1117, 302);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(145, 53);
			this->textBox3->TabIndex = 15;
			this->textBox3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(587, 354);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(489, 46);
			this->label4->TabIndex = 16;
			this->label4->Text = L"*New Economic seat price";
			this->label4->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(1117, 354);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(145, 53);
			this->textBox4->TabIndex = 17;
			this->textBox4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(587, 406);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(521, 46);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Current Executive seat price";
			this->label5->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(1117, 406);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(145, 53);
			this->textBox5->TabIndex = 19;
			this->textBox5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(592, 458);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(484, 46);
			this->label6->TabIndex = 20;
			this->label6->Text = L"*New Executive seat price";
			this->label6->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(1117, 458);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(145, 53);
			this->textBox6->TabIndex = 21;
			this->textBox6->Visible = false;
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(1117, 510);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(145, 53);
			this->textBox7->TabIndex = 22;
			this->textBox7->Visible = false;
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(1117, 562);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(145, 53);
			this->textBox8->TabIndex = 23;
			this->textBox8->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(592, 510);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(509, 46);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Current Business seat price";
			this->label7->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(592, 562);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(472, 46);
			this->label8->TabIndex = 25;
			this->label8->Text = L"*New Business seat price";
			this->label8->Visible = false;
			// 
			// ReadFeedback
			// 
			this->ReadFeedback->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ReadFeedback.BackgroundImage")));
			this->ReadFeedback->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ReadFeedback->FlatAppearance->BorderSize = 0;
			this->ReadFeedback->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ReadFeedback->Location = System::Drawing::Point(1010, 530);
			this->ReadFeedback->Name = L"ReadFeedback";
			this->ReadFeedback->Size = System::Drawing::Size(454, 242);
			this->ReadFeedback->TabIndex = 26;
			this->ReadFeedback->UseVisualStyleBackColor = true;
			this->ReadFeedback->Click += gcnew System::EventHandler(this, &MHM_Admin0::ReadFeedback_Click);
			// 
			// Continue4
			// 
			this->Continue4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Continue4.BackgroundImage")));
			this->Continue4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Continue4->FlatAppearance->BorderSize = 0;
			this->Continue4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue4->Location = System::Drawing::Point(789, 641);
			this->Continue4->Name = L"Continue4";
			this->Continue4->Size = System::Drawing::Size(324, 98);
			this->Continue4->TabIndex = 27;
			this->Continue4->UseVisualStyleBackColor = true;
			this->Continue4->Visible = false;
			this->Continue4->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue4_Click);
			// 
			// FeedbackBG
			// 
			this->FeedbackBG->BackColor = System::Drawing::Color::Transparent;
			this->FeedbackBG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->FeedbackBG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FeedbackBG.Image")));
			this->FeedbackBG->Location = System::Drawing::Point(530, 120);
			this->FeedbackBG->Name = L"FeedbackBG";
			this->FeedbackBG->Size = System::Drawing::Size(806, 678);
			this->FeedbackBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->FeedbackBG->TabIndex = 28;
			this->FeedbackBG->TabStop = false;
			this->FeedbackBG->Visible = false;
			// 
			// FBseatNoLabel
			// 
			this->FBseatNoLabel->AutoSize = true;
			this->FBseatNoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FBseatNoLabel->Location = System::Drawing::Point(725, 212);
			this->FBseatNoLabel->Name = L"FBseatNoLabel";
			this->FBseatNoLabel->Size = System::Drawing::Size(187, 46);
			this->FBseatNoLabel->TabIndex = 29;
			this->FBseatNoLabel->Text = L"Seat No :";
			this->FBseatNoLabel->Visible = false;
			// 
			// FeedbackLabel
			// 
			this->FeedbackLabel->AutoSize = true;
			this->FeedbackLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FeedbackLabel->Location = System::Drawing::Point(592, 275);
			this->FeedbackLabel->Name = L"FeedbackLabel";
			this->FeedbackLabel->Size = System::Drawing::Size(206, 46);
			this->FeedbackLabel->TabIndex = 30;
			this->FeedbackLabel->Text = L"Feedback:";
			this->FeedbackLabel->Visible = false;
			// 
			// RatingLabel
			// 
			this->RatingLabel->AutoSize = true;
			this->RatingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RatingLabel->Location = System::Drawing::Point(766, 585);
			this->RatingLabel->Name = L"RatingLabel";
			this->RatingLabel->Size = System::Drawing::Size(157, 46);
			this->RatingLabel->TabIndex = 31;
			this->RatingLabel->Text = L"Rating :";
			this->RatingLabel->Visible = false;
			// 
			// FBSeatNo
			// 
			this->FBSeatNo->Enabled = false;
			this->FBSeatNo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FBSeatNo->Location = System::Drawing::Point(941, 205);
			this->FBSeatNo->Name = L"FBSeatNo";
			this->FBSeatNo->Size = System::Drawing::Size(187, 53);
			this->FBSeatNo->TabIndex = 32;
			this->FBSeatNo->Visible = false;
			// 
			// Feedback
			// 
			this->Feedback->Enabled = false;
			this->Feedback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Feedback->Location = System::Drawing::Point(600, 323);
			this->Feedback->Multiline = true;
			this->Feedback->Name = L"Feedback";
			this->Feedback->Size = System::Drawing::Size(662, 188);
			this->Feedback->TabIndex = 33;
			this->Feedback->Visible = false;
			// 
			// Rating
			// 
			this->Rating->Enabled = false;
			this->Rating->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rating->Location = System::Drawing::Point(941, 582);
			this->Rating->Name = L"Rating";
			this->Rating->Size = System::Drawing::Size(187, 53);
			this->Rating->TabIndex = 34;
			this->Rating->Visible = false;
			// 
			// NextFeedback
			// 
			this->NextFeedback->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)), static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->NextFeedback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextFeedback->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->NextFeedback->Location = System::Drawing::Point(1184, 157);
			this->NextFeedback->Name = L"NextFeedback";
			this->NextFeedback->Size = System::Drawing::Size(78, 44);
			this->NextFeedback->TabIndex = 35;
			this->NextFeedback->Text = L"Next";
			this->NextFeedback->UseVisualStyleBackColor = false;
			this->NextFeedback->Visible = false;
			this->NextFeedback->Click += gcnew System::EventHandler(this, &MHM_Admin0::NextFeedback_Click);
			// 
			// ScheduleListContinue
			// 
			this->ScheduleListContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->ScheduleListContinue->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ScheduleListContinue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ScheduleListContinue->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ScheduleListContinue->Location = System::Drawing::Point(759, 803);
			this->ScheduleListContinue->Name = L"ScheduleListContinue";
			this->ScheduleListContinue->Size = System::Drawing::Size(324, 98);
			this->ScheduleListContinue->TabIndex = 44;
			this->ScheduleListContinue->Text = L"Update Schedule";
			this->ScheduleListContinue->UseVisualStyleBackColor = false;
			this->ScheduleListContinue->Visible = false;
			this->ScheduleListContinue->Click += gcnew System::EventHandler(this, &MHM_Admin0::ScheduleListContinue_Click);
			// 
			// ScheduleRoutesBox
			// 
			this->ScheduleRoutesBox->Controls->Add(this->Hours);
			this->ScheduleRoutesBox->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->ScheduleRoutesBox->Location = System::Drawing::Point(633, 250);
			this->ScheduleRoutesBox->Name = L"ScheduleRoutesBox";
			this->ScheduleRoutesBox->Size = System::Drawing::Size(629, 404);
			this->ScheduleRoutesBox->TabIndex = 45;
			this->ScheduleRoutesBox->Visible = false;
			// 
			// Hours
			// 
			this->Hours->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(177)), static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->Hours->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Hours->CheckOnClick = true;
			this->Hours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hours->ForeColor = System::Drawing::Color::White;
			this->Hours->FormattingEnabled = true;
			this->Hours->Location = System::Drawing::Point(3, 3);
			this->Hours->Name = L"Hours";
			this->Hours->ScrollAlwaysVisible = true;
			this->Hours->Size = System::Drawing::Size(626, 369);
			this->Hours->TabIndex = 46;
			this->Hours->Visible = false;
			// 
			// TrainsBG
			// 
			this->TrainsBG->BackColor = System::Drawing::Color::Transparent;
			this->TrainsBG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->TrainsBG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TrainsBG.Image")));
			this->TrainsBG->Location = System::Drawing::Point(530, 119);
			this->TrainsBG->Name = L"TrainsBG";
			this->TrainsBG->Size = System::Drawing::Size(806, 678);
			this->TrainsBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->TrainsBG->TabIndex = 46;
			this->TrainsBG->TabStop = false;
			this->TrainsBG->Visible = false;
			// 
			// trainsButton
			// 
			this->trainsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"trainsButton.BackgroundImage")));
			this->trainsButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->trainsButton->FlatAppearance->BorderSize = 0;
			this->trainsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->trainsButton->Location = System::Drawing::Point(1293, 228);
			this->trainsButton->Name = L"trainsButton";
			this->trainsButton->Size = System::Drawing::Size(454, 242);
			this->trainsButton->TabIndex = 47;
			this->trainsButton->UseVisualStyleBackColor = true;
			this->trainsButton->Click += gcnew System::EventHandler(this, &MHM_Admin0::trainsButton_Click);
			// 
			// Continue5
			// 
			this->Continue5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Continue5.BackgroundImage")));
			this->Continue5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Continue5->FlatAppearance->BorderSize = 0;
			this->Continue5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Continue5->Location = System::Drawing::Point(759, 660);
			this->Continue5->Name = L"Continue5";
			this->Continue5->Size = System::Drawing::Size(324, 98);
			this->Continue5->TabIndex = 49;
			this->Continue5->UseVisualStyleBackColor = true;
			this->Continue5->Visible = false;
			this->Continue5->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue5_Click);
			// 
			// TrainsBox
			// 
			this->TrainsBox->Controls->Add(this->TrainsList);
			this->TrainsBox->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->TrainsBox->Location = System::Drawing::Point(600, 312);
			this->TrainsBox->Name = L"TrainsBox";
			this->TrainsBox->Size = System::Drawing::Size(662, 332);
			this->TrainsBox->TabIndex = 50;
			this->TrainsBox->Visible = false;
			// 
			// TrainsList
			// 
			this->TrainsList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(177)), static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->TrainsList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TrainsList->CheckOnClick = true;
			this->TrainsList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TrainsList->ForeColor = System::Drawing::Color::White;
			this->TrainsList->FormattingEnabled = true;
			this->TrainsList->Location = System::Drawing::Point(3, 3);
			this->TrainsList->Name = L"TrainsList";
			this->TrainsList->ScrollAlwaysVisible = true;
			this->TrainsList->Size = System::Drawing::Size(659, 328);
			this->TrainsList->TabIndex = 51;
			this->TrainsList->Visible = false;
			// 
			// TrainListContinue
			// 
			this->TrainListContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(77)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->TrainListContinue->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->TrainListContinue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TrainListContinue->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->TrainListContinue->Location = System::Drawing::Point(759, 803);
			this->TrainListContinue->Name = L"TrainListContinue";
			this->TrainListContinue->Size = System::Drawing::Size(324, 98);
			this->TrainListContinue->TabIndex = 52;
			this->TrainListContinue->Text = L"Update Trains";
			this->TrainListContinue->UseVisualStyleBackColor = false;
			this->TrainListContinue->Visible = false;
			this->TrainListContinue->Click += gcnew System::EventHandler(this, &MHM_Admin0::TrainListContinue_Click);
			// 
			// Finish
			// 
			this->Finish->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->Finish->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Finish.BackgroundImage")));
			this->Finish->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Finish->FlatAppearance->BorderSize = 0;
			this->Finish->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Finish->Location = System::Drawing::Point(1597, 909);
			this->Finish->Name = L"Finish";
			this->Finish->Size = System::Drawing::Size(236, 129);
			this->Finish->TabIndex = 53;
			this->Finish->UseVisualStyleBackColor = false;
			this->Finish->Click += gcnew System::EventHandler(this, &MHM_Admin0::Finish_Click);
			// 
			// MHM_Admin0
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(177)), static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->Finish);
			this->Controls->Add(this->TrainListContinue);
			this->Controls->Add(this->TrainsBox);
			this->Controls->Add(this->Continue5);
			this->Controls->Add(this->TrainsBG);
			this->Controls->Add(this->ScheduleListContinue);
			this->Controls->Add(this->ScheduleRoutesBox);
			this->Controls->Add(this->Continue2);
			this->Controls->Add(this->schedulesBox);
			this->Controls->Add(this->NextFeedback);
			this->Controls->Add(this->Continue4);
			this->Controls->Add(this->Rating);
			this->Controls->Add(this->RatingLabel);
			this->Controls->Add(this->Feedback);
			this->Controls->Add(this->FeedbackLabel);
			this->Controls->Add(this->FBSeatNo);
			this->Controls->Add(this->FBseatNoLabel);
			this->Controls->Add(this->FeedbackBG);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Continue3);
			this->Controls->Add(this->fareBG);
			this->Controls->Add(this->priceSetter);
			this->Controls->Add(this->routes);
			this->Controls->Add(this->Continue1);
			this->Controls->Add(this->RouteListBox);
			this->Controls->Add(this->routesButton);
			this->Controls->Add(this->schedulesButton);
			this->Controls->Add(this->ReadFeedback);
			this->Controls->Add(this->trainsButton);
			this->DoubleBuffered = true;
			this->Name = L"MHM_Admin0";
			this->Text = L"MHM_Admin0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulesBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fareBG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FeedbackBG))->EndInit();
			this->ScheduleRoutesBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrainsBG))->EndInit();
			this->TrainsBox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//------------------------ROUTES BUTTON CLICKED----------------------------------------------------
	private: System::Void routesButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue1->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->ReadFeedback->Visible = false;
		this->trainsButton->Visible = false;
		this->routes->Visible = true;
		this->RouteListBox->Visible = true;
	}

		   //------------------------ROUTES CHECK LIST BOX BUTTON CLICKED--------------------------------------
	private: System::Void routes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

	}

		   //------------------------ROUTES CONTINUE BUTTON CLICKED---------------------------------------------
	private: System::Void Continue1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->routes->Visible = false;
		this->Continue1->Visible = false;
		this->RouteListBox->Visible = false;
		this->routesButton->Visible = true;
		this->schedulesButton->Visible = true;
		this->priceSetter->Visible = true;
		this->ReadFeedback->Visible = true;
		this->trainsButton->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");


		for (int i = 0; i < routes->Items->Count; i++)
		{
			// Determine the availability to write to the database based on checked state of routes check box list
			int availabile = (routes->GetItemChecked(i)) ? 1 : 0;
			a[i].availabilitySetter(availabile);
		}
		//implement the updated data in the database
		admin.ChangeRouteAvailability(a);
	}

		   //-------------------------------SCHEDULES BUTTON CLICKED----------------------------------------------
	private: System::Void schedulesButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue2->Visible = true;
		this->ScheduleRoutesBox->Visible = true;
		this->schedulesBox->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->ReadFeedback->Visible = false;
		this->trainsButton->Visible = false;
	}

		   //----------------------------SCHEDULES CONTINUE BUTTON CLICKED-------------------------------------------
	private: System::Void Continue2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");
		this->Continue2->Visible = false;
		this->schedulesBox->Visible = false;
		this->routesButton->Visible = true;
		this->schedulesButton->Visible = true;
		this->priceSetter->Visible = true;
		this->ReadFeedback->Visible = true;
		this->trainsButton->Visible = true;
		this->schedulesBox->Visible = false;
		this->ScheduleRoutesBox->Visible = false;
	}
		   //----------------------------PRICE SETTER BUTTON CLICKED-------------------------------------------
	private: System::Void priceSetter_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue3->Visible = true;
		this->label1->Visible = true;
		this->label2->Visible = true;
		this->label3->Visible = true;
		this->label4->Visible = true;
		this->label5->Visible = true;
		this->label6->Visible = true;
		this->label7->Visible = true;
		this->label8->Visible = true;
		this->textBox1->Visible = true;
		this->textBox2->Visible = true;
		this->textBox3->Visible = true;
		this->textBox4->Visible = true;
		this->textBox5->Visible = true;
		this->textBox6->Visible = true;
		this->textBox7->Visible = true;
		this->textBox8->Visible = true;
		this->fareBG->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->ReadFeedback->Visible = false;
		this->trainsButton->Visible = false;
		
		this->textBox1->Text = System::Convert::ToString(admin.routePriceGetter());
		this->textBox5->Text = System::Convert::ToString(admin.ExecutiveGetter());
		this->textBox3->Text = System::Convert::ToString(admin.EconomicGetter());
		this->textBox7->Text = System::Convert::ToString(admin.BusinessGetter());

	}
		   //----------------------------PRICE SETTER CONTINE BUTTON CLICKED------------------------------------
	private: System::Void Continue3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//checks for input
		if (textBox2->Text == "")
		{
			MessageBox::Show("Please enter a value.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!isPositiveInteger(textBox2->Text))
		{
			MessageBox::Show("Please enter a positive integer.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox2->Text = "";
		}
		else if (textBox4->Text == "")
		{
			MessageBox::Show("Please enter a value.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!isPositiveInteger(textBox4->Text))
		{
			MessageBox::Show("Please enter a positive integer.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox4->Text = "";
		}
		else if (textBox6->Text == "")
		{
			MessageBox::Show("Please enter a value.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!isPositiveInteger(textBox6->Text))
		{
			MessageBox::Show("Please enter a positive integer.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox6->Text = "";
		}
		else if (textBox8->Text == "")
		{
			MessageBox::Show("Please enter a value.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!isPositiveInteger(textBox8->Text))
		{
			MessageBox::Show("Please enter a positive integer.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox8->Text = "";
		}
		else
		{
			this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");
			this->routesButton->Visible = true;
			this->schedulesButton->Visible = true;
			this->priceSetter->Visible = true;
			this->ReadFeedback->Visible = true;
			this->trainsButton->Visible = true;
			this->fareBG->Visible = false;
			this->label1->Visible = false;
			this->label2->Visible = false;
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->label8->Visible = false;
			this->textBox1->Visible = false;
			this->textBox2->Visible = false;
			this->textBox3->Visible = false;
			this->textBox4->Visible = false;
			this->textBox5->Visible = false;
			this->textBox6->Visible = false;
			this->textBox7->Visible = false;
			this->textBox8->Visible = false;
			this->Continue3->Visible = false;

			admin.SetFare(textBox2->Text, textBox6->Text, textBox4->Text, textBox8->Text, admin);

			textBox2->Text = "";
			textBox4->Text = "";
			textBox6->Text = "";
			textBox8->Text = "";
		}
	}

		   //----------------------------FEEDBACK READER BUTTON CLICKED------------------------------------
	private: System::Void ReadFeedback_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue4->Visible = true;
		this->FBseatNoLabel->Visible = true;
		this->FBSeatNo->Visible = true;
		this->FeedbackLabel->Visible = true;
		this->Feedback->Visible = true;
		this->RatingLabel->Visible = true;
		this->Rating->Visible = true;
		this->NextFeedback->Visible = true;
		this->FeedbackBG->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->ReadFeedback->Visible = false;
		this->trainsButton->Visible = false;
	}

	int p = 0;
		   //----------------------------FEEDBACK READER CONTINUE BUTTON CLICKED----------------------------
	private: System::Void Continue4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");
		this->routesButton->Visible = true;
		this->schedulesButton->Visible = true;
		this->priceSetter->Visible = true;
		this->ReadFeedback->Visible = true;
		this->trainsButton->Visible = true;
		this->FeedbackBG->Visible = false;
		this->Continue4->Visible = false;
		this->FBseatNoLabel->Visible = false;
		this->FBSeatNo->Visible = false;
		this->FeedbackLabel->Visible = false;
		this->Feedback->Visible = false;
		this->RatingLabel->Visible = false;
		this->Rating->Visible = false;
		this->NextFeedback->Visible = false;
		p = 0;
	}
		   //----------------------------FEEDBACK READER NEXT BUTTON CLICKED-----------------------------
	private: System::Void NextFeedback_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (p < feedbacks)
		{
			this->FBSeatNo->Text = gcnew System::String(a[p].FeedbackSeatNoGetter().c_str());
			this->Feedback->Text = gcnew System::String(a[p].FeedbackGetter().c_str());
			this->Rating->Text = gcnew System::String(a[p].RatingsGetter().c_str());
			p++;
		}
	}
		   //----------------------------UPDATE SCHEDULE BUTTON CLICKED--------------------------------
	private: System::Void ScheduleListContinue_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int* hourBool = new int[24];
		for (int i = 0; i < Hours->Items->Count; i++)
		{
			//Get the updated data from the check box into array
			hourBool[i] = (Hours->GetItemChecked(i)) ? 1 : 0;
		}
		a[index].scheduleSetter(hourBool);

		//implement the updated data in the database
		admin.SetAvailableSchedule(a);

		Hours->Items->Clear();	//clears the checkbox, so data from another button can be placed in it
		this->Continue2->Visible = true;
		this->Hours->Visible = false;
		this->ScheduleListContinue->Visible = false;
	}
	
		  //----------------------------TRAINS BUTTON CLICKED--------------------------------
	private: System::Void trainsButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->TrainsBox->Visible = true;
		this->Continue5->Visible = true;
		this->TrainsBG->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->ReadFeedback->Visible = false;
		this->trainsButton->Visible = false;
	}
	
	
	private: System::Void Continue5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->routesButton->Visible = true;
		this->schedulesButton->Visible = true;
		this->priceSetter->Visible = true;
		this->ReadFeedback->Visible = true;
		this->trainsButton->Visible = true;
		this->TrainsBG->Visible = false;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\AdminBG.png");
		this->Continue5->Visible = false;
		this->TrainsBox->Visible = false;
	}
	

	private: System::Void TrainListContinue_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int* trainBool = new int[3];
		for (int i = 0; i < TrainsList->Items->Count; i++)
		{
			//Get the updated data from the check box into array
			trainBool[i] = (TrainsList->GetItemChecked(i)) ? 1 : 0;
		}
		a[index1].trainsSetter(trainBool);

		//implement the updated data in the database
		admin.SetAvailabilityOfTrain(a);

		TrainsList->Items->Clear();	//clears the checkbox, so data from another button can be placed in it
		this->Continue5->Visible = true;
		this->TrainsList->Visible = false;
		this->TrainListContinue->Visible = false;
	}
	
	private: System::Void Finish_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
};
}
#endif