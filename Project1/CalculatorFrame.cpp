#include "CalculatorFrame.h"
#include <wx/wx.h>

/// <summary>
/// The Main Frame for the Calculator Application
/// </summary>
CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)) {

}