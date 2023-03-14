#include "CalculatorFrame.h"
#include <wx/wx.h>

/// <summary>
/// The Main Frame for the Calculator Application
/// </summary>
CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	displayPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	displayPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));

	wxBoxSizer* containerSizer;
	containerSizer = new wxBoxSizer(wxVERTICAL);

	displayText = new wxStaticText(displayPanel, wxID_ANY, "");
	displayText->SetFont(wxFont(24, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New")));

	containerSizer->Add(displayText, 0, wxALL, 5);

	displayPanel->SetSizer(containerSizer);
	displayPanel->Layout();
	containerSizer->Fit(displayPanel);
	mainSizer->Add(displayPanel, 1, wxALL | wxEXPAND, 5);

	wxFlexGridSizer* numPad;
	numPad = new wxFlexGridSizer(4, 4, 0, 0);
	numPad->AddGrowableCol(3);
	numPad->AddGrowableRow(0);
	numPad->AddGrowableRow(1);
	numPad->AddGrowableRow(2);
	numPad->AddGrowableRow(3);
	numPad->SetFlexibleDirection(wxBOTH);
	numPad->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_ALL);

	sevenBtn = new wxButton(this, wxID_ANY, wxT("7"));
	numPad->Add(sevenBtn, 0, wxALL | wxEXPAND, 5);

	eightBtn = new wxButton(this, wxID_ANY, wxT("8"));
	numPad->Add(eightBtn, 0, wxALL | wxEXPAND, 5);

	nineBtn = new wxButton(this, wxID_ANY, wxT("9"));
	numPad->Add(nineBtn, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* bracketSizer;
	bracketSizer = new wxBoxSizer(wxHORIZONTAL);

	fBracketBtn = new wxButton(this, wxID_ANY, wxT("("));
	bracketSizer->Add(fBracketBtn, 0, wxALL | wxEXPAND, 5);

	bBracketBtn = new wxButton(this, wxID_ANY, wxT(")"));
	bracketSizer->Add(bBracketBtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(bracketSizer, 1, wxEXPAND, 5);

	fourBtn = new wxButton(this, wxID_ANY, wxT("4"));
	numPad->Add(fourBtn, 0, wxALL | wxEXPAND, 5);

	fiveBtn = new wxButton(this, wxID_ANY, wxT("5"));
	numPad->Add(fiveBtn, 0, wxALL | wxEXPAND, 5);

	sixBtn = new wxButton(this, wxID_ANY, wxT("6"));
	numPad->Add(sixBtn, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* multDivSizer;
	multDivSizer = new wxBoxSizer(wxHORIZONTAL);

	multbtn = new wxButton(this, wxID_ANY, wxT("x"));
	multDivSizer->Add(multbtn, 0, wxALL | wxEXPAND, 5);

	divbtn = new wxButton(this, wxID_ANY, wxT("/"));
	multDivSizer->Add(divbtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(multDivSizer, 1, wxEXPAND, 5);

	oneBtn = new wxButton(this, wxID_ANY, wxT("1"));
	numPad->Add(oneBtn, 0, wxALL | wxEXPAND, 5);

	twoBtn = new wxButton(this, wxID_ANY, wxT("2"));
	numPad->Add(twoBtn, 0, wxALL | wxEXPAND, 5);

	threeBtn = new wxButton(this, wxID_ANY, wxT("3"));
	numPad->Add(threeBtn, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* plusMinSizer;
	plusMinSizer = new wxBoxSizer(wxHORIZONTAL);

	plusBtn = new wxButton(this, wxID_ANY, wxT("+"));
	plusMinSizer->Add(plusBtn, 0, wxALL | wxEXPAND, 5);

	minusBtn = new wxButton(this, wxID_ANY, wxT("-"));
	plusMinSizer->Add(minusBtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(plusMinSizer, 1, wxEXPAND, 5);

	zeroBtn = new wxButton(this, wxID_ANY, wxT("0"));
	numPad->Add(zeroBtn, 0, wxALL | wxEXPAND, 5);

	decimalBtn = new wxButton(this, wxID_ANY, wxT("."));
	numPad->Add(decimalBtn, 0, wxALL | wxEXPAND, 5);

	negBtn = new wxButton(this, wxID_ANY, wxT("(-)"));
	numPad->Add(negBtn, 0, wxALL | wxEXPAND, 5);

	equalBtn = new wxButton(this, wxID_ANY, wxT("="));
	numPad->Add(equalBtn, 0, wxALL | wxEXPAND, 5);

	mainSizer->Add(numPad, 3, wxEXPAND, 5);

	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	// Assigned Events
	oneBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onOneClick, this);
}

void CalculatorFrame::onOneClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "1");
	displayText->Wrap(-1);
}