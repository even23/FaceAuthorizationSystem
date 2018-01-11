#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FaceAuthorizationSystem::MainWindow window;
	Application::Run(%window);
	Application::Exit();
}
