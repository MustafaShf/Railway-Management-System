#include "MHM_User.h"
#include"UserFeedback.h"
#include"MHM_Payment.h"
#include"paymentSuccessfull.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);


    //Run the window
   Application::Run(gcnew MHMUser::MHM_User());

    return 0;
}
//this->BackgroundImage = System::Drawing::Image::FromFile("Assets\\FareCalComplete.png");
