#include "MHM_Admin0.h"
#include "MHM_Functions.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    int* all_routes = nullptr, ** schedules = nullptr, number_of_routes = 0;
    string* start = nullptr, * end = nullptr;
    number_of_routes = Admin::GetData(all_routes, start, end, schedules);


    // Create and run your main form
    Application::Run(gcnew MHMTMSV21::MHM_Admin0());
  

    return 0;
}
