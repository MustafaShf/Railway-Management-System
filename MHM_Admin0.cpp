#include "MHM_Admin0.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    //Run the window
    Application::Run(gcnew MHMTMSV21::MHM_Admin0());


    return 0;
}
