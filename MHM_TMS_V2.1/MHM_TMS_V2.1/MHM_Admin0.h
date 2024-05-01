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
			int rowCount = admin.GetData(a);

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->schedulesBox))->BeginInit();
			this->SuspendLayout();
			// 
			// routesButton
			// 
			this->routesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"routesButton.BackgroundImage")));
			this->routesButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->routesButton->FlatAppearance->BorderSize = 0;
			this->routesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->routesButton->Location = System::Drawing::Point(175, 196);
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
			this->schedulesButton->Location = System::Drawing::Point(1259, 196);
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
			this->Continue2->Location = System::Drawing::Point(759, 620);
			this->Continue2->Name = L"Continue2";
			this->Continue2->Size = System::Drawing::Size(324, 98);
			this->Continue2->TabIndex = 6;
			this->Continue2->UseVisualStyleBackColor = true;
			this->Continue2->Visible = false;
			this->Continue2->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue2_Click);
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
			this->ResumeLayout(false);

		}
#pragma endregion
		//------------------------ROUTES BUTTON CLICKED----------------------------------------------------
	private: System::Void routesButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue1->Visible = true;
		this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\BlurClearBG.png");
		this->routesButton->Visible = false;
		this->schedulesButton->Visible = false;
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
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

	}
	};
}
#endif