#pragma once
#include"DataStorers.h"	//gets us all the data modifiers plus class functions

namespace MHMTMSV21
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MHM_Admin0
	/// </summary>
	public ref class MHM_Admin0 : public System::Windows::Forms::Form
	{
	public:
		MHM_Admin0(void)
		{
			//--------------------------------------------------INITIALIZE AND EARLY STUFF ETC-------------------
			InitializeComponent();
			routes->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			//routes->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MHM_Admin0::routes_DrawItem);


			//RouteListBox Data
			int i = 0;
			while (i < number_of_routes)
			{
				int checkboxState = all_routes[i];
				int totalLength = strlen(Start[0].c_str()) + strlen(" to ") + strlen(End[0].c_str()) + 1; // +1 for null terminator

				String^ itemText = gcnew String((Start[i] + " to " + End[i]).c_str());

				// Adds option to routesbox
				routes->Items->Add(itemText);

				//Sets the checked state based on availability from the database
				routes->SetItemChecked(routes->Items->Count - 1, checkboxState == 1);
				i++;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MHM_Admin0()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ routesButton;

	private: System::Windows::Forms::CheckedListBox^ routes;
	private: System::Windows::Forms::Button^ Continue1;
	private: System::Windows::Forms::PictureBox^ RouteListBox;








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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->BeginInit();
			this->SuspendLayout();
			// 
			// routesButton
			// 
			this->routesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"routesButton.BackgroundImage")));
			this->routesButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->routesButton->FlatAppearance->BorderSize = 0;
			this->routesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->routesButton->Location = System::Drawing::Point(128, 103);
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
			this->routes->Location = System::Drawing::Point(704, 267);
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
			this->RouteListBox->BackColor = System::Drawing::Color::White;
			this->RouteListBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->RouteListBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RouteListBox.Image")));
			this->RouteListBox->Location = System::Drawing::Point(530, 112);
			this->RouteListBox->Name = L"RouteListBox";
			this->RouteListBox->Size = System::Drawing::Size(806, 678);
			this->RouteListBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->RouteListBox->TabIndex = 3;
			this->RouteListBox->TabStop = false;
			this->RouteListBox->Visible = false;
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
			this->Controls->Add(this->routes);
			this->Controls->Add(this->Continue1);
			this->Controls->Add(this->RouteListBox);
			this->Controls->Add(this->routesButton);
			this->DoubleBuffered = true;
			this->Name = L"MHM_Admin0";
			this->Text = L"MHM_Admin0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RouteListBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//------------------------ROUTES BUTTON CLICKED----------------------------------------------------
	private: System::Void routesButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue1->Visible = true;
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

		for (int i = 0; i < routes->Items->Count; i++)
		{
			// Determine the availability to write to the database based on checked state of routes check box list
			int availability = (routes->GetItemChecked(i)) ? 1 : 0;
			all_routes[i] = availability;
		}
		//implement the updated data in the database
		Admin::ChangeRouteAvailability(all_routes);
	}


	};
}