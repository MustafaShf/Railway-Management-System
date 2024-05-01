#ifndef Admin_H
#define Admin_H

#include"MHM_Functions.h"

dataRetriever* a;
Admin admin;

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
			int rowCount = admin.GetData(a, admin);

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
				delete a;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulesBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fareBG))->BeginInit();
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
			this->Continue2->Location = System::Drawing::Point(759, 623);
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
			this->priceSetter->Location = System::Drawing::Point(530, 530);
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
			// MHM_Admin0
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(177)), static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->Continue2);
			this->Controls->Add(this->schedulesBox);
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
			this->DoubleBuffered = true;
			this->Name = L"MHM_Admin0";
			this->Text = L"MHM_Admin0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulesBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fareBG))->EndInit();
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
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
		this->priceSetter->Visible = false;
		this->Continue2->Visible = true;
		this->schedulesBox->Visible = true;
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
};
}
#endif