#include "MainApp.h"
#include "CalculatorFrame.h"
#include <wx/wx.h>

// Initiate wxApp
wxIMPLEMENT_APP(MainApp);

// Start Method
bool MainApp::OnInit() {
	CalculatorFrame* mainFrame = new CalculatorFrame();
	mainFrame->SetClientSize(425, 550);
	mainFrame->SetIcon(wxIcon("aaaaaaaa"));
	mainFrame->Center();
	mainFrame->Show();
	return true;
}