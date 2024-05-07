#include "MHM_User.h"

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
