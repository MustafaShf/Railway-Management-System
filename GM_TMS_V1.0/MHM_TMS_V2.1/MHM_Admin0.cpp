#include "MHM_Admin0.h"
#include "payment.h"
#include "UserFeedback.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);


    //Run the window
    //Application::Run(gcnew MHMTMSV21::MHM_Admin0());
   // Application::Run(gcnew MHMTMSV21::UserFeedback());
   // Application::Run(gcnew MHMTMSV21::UserFeedback());
    //UserFeedBack::UserFeedBack userfeed;

    //userfeed.ShowDialog();
   Application::Run(gcnew MHMTMSV21::payment());


    return 0;
}
