#include "UserSignIn.h"
#include "USER.h"
#include "Accounts.h"
#include "Account.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);

	Application::EnableVisualStyles();

	OOPProjectGUI::UserSignIn frm;

	Application::Run(% frm);

}