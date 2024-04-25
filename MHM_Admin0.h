#pragma once

namespace MHMTMSV21 {

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
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::CheckedListBox^ routes;
	private: System::Windows::Forms::Button^ Continue1;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MHM_Admin0::typeid));
			this->routesButton = (gcnew System::Windows::Forms::Button());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->routes = (gcnew System::Windows::Forms::CheckedListBox());
			this->Continue1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// routesButton
			// 
			this->routesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"routesButton.BackgroundImage")));
			this->routesButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->routesButton->FlatAppearance->BorderSize = 0;
			this->routesButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->routesButton->Location = System::Drawing::Point(85, 67);
			this->routesButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->routesButton->Name = L"routesButton";
			this->routesButton->Size = System::Drawing::Size(303, 157);
			this->routesButton->TabIndex = 0;
			this->routesButton->UseVisualStyleBackColor = true;
			this->routesButton->Click += gcnew System::EventHandler(this, &MHM_Admin0::routesButton_Click);
			// 
			// routes
			// 
			this->routes->BackColor = System::Drawing::SystemColors::Highlight;
			this->routes->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->routes->ForeColor = System::Drawing::SystemColors::Info;
			this->routes->FormattingEnabled = true;
			this->routes->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Lahore to Karachi", L"Lahore to Murree", L"Karachi to Lahore",
					L"Karachi to Murree", L"Murree to Lahore", L"Murree to Karachi"
			});
			this->routes->Location = System::Drawing::Point(132, 228);
			this->routes->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->routes->Name = L"routes";
			this->routes->ScrollAlwaysVisible = true;
			this->routes->Size = System::Drawing::Size(225, 244);
			this->routes->TabIndex = 1;
			this->routes->Visible = false;
			this->routes->SelectedIndexChanged += gcnew System::EventHandler(this, &MHM_Admin0::routes_SelectedIndexChanged);
			// 
			// Continue1
			// 
			this->Continue1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Continue1->Font = (gcnew System::Drawing::Font(L"Arial Black", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continue1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Continue1->Location = System::Drawing::Point(180, 422);
			this->Continue1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Continue1->Name = L"Continue1";
			this->Continue1->Size = System::Drawing::Size(101, 32);
			this->Continue1->TabIndex = 2;
			this->Continue1->Text = L"Continue";
			this->Continue1->UseVisualStyleBackColor = false;
			this->Continue1->Visible = false;
			this->Continue1->Click += gcnew System::EventHandler(this, &MHM_Admin0::Continue1_Click);
			// 
			// MHM_Admin0
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1284, 701);
			this->Controls->Add(this->Continue1);
			this->Controls->Add(this->routes);
			this->Controls->Add(this->routesButton);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MHM_Admin0";
			this->Text = L"MHM_Admin0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void routesButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Continue1->Visible = true;
		this->routes->Visible = true;
	}
	private: System::Void routes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void Continue1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->routes->Visible = false;
		this->Continue1->Visible = false;
	}
};
}
