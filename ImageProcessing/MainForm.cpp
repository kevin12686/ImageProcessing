#include "MainForm.h"
#include <Windows.h>

using namespace ImageProcessing; // This is your project name

[STAThread]
int main(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	return 0;
}