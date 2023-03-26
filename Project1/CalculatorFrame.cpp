#include "CalculatorFrame.h"
#include "Term.h"
#include <wx/wx.h>
#include <cmath>
#include <vector>

using namespace std;

/// <summary>
/// The Main Frame for the Calculator Application
/// </summary>
CalculatorFrame::CalculatorFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxVERTICAL);

	displayPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(), wxTAB_TRAVERSAL);
	displayPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));

	wxBoxSizer* containerSizer;
	containerSizer = new wxBoxSizer(wxHORIZONTAL);

	displayText = new wxStaticText(displayPanel, wxID_ANY, "");
	displayText->SetFont(wxFont(24, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New")));

	containerSizer->Add(displayText, 1, wxALL | wxEXPAND, 5);

	// Trackers
	activeTerms = {
		// Main Term
		new Term(),
	};
	currentTerm = nullptr;
	currentOperation = termNULL;
	currentNumber = 0;
	decimalPoint = 0;
	positive = true;

	CreateStatusBar();

	displayPanel->SetSizer(containerSizer);
	displayPanel->Layout();
	containerSizer->Fit(displayPanel);
	mainSizer->Add(displayPanel, 1, wxALL | wxEXPAND | wxFIXED_MINSIZE, 5);

	wxFlexGridSizer* numPad;
	numPad = new wxFlexGridSizer(4, 4, 0, 0);
	numPad->AddGrowableCol(3);
	numPad->AddGrowableRow(0);
	numPad->AddGrowableRow(1);
	numPad->AddGrowableRow(2);
	numPad->AddGrowableRow(3);
	numPad->SetFlexibleDirection(wxBOTH);
	numPad->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_ALL);

	numPadBtn[7] = new wxButton(this, wxID_ANY, wxT("7"));
	numPad->Add(numPadBtn[7], 0, wxALL | wxEXPAND, 5);

	numPadBtn[8] = new wxButton(this, wxID_ANY, wxT("8"));
	numPad->Add(numPadBtn[8], 0, wxALL | wxEXPAND, 5);

	numPadBtn[9] = new wxButton(this, wxID_ANY, wxT("9"));
	numPad->Add(numPadBtn[9], 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* bracketSizer;
	bracketSizer = new wxBoxSizer(wxHORIZONTAL);

	fBracketBtn = new wxButton(this, wxID_ANY, wxT("("));
	bracketSizer->Add(fBracketBtn, 0, wxALL | wxEXPAND, 5);

	bBracketBtn = new wxButton(this, wxID_ANY, wxT(")"));
	bracketSizer->Add(bBracketBtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(bracketSizer, 1, wxEXPAND, 5);

	numPadBtn[4] = new wxButton(this, wxID_ANY, wxT("4"));
	numPad->Add(numPadBtn[4], 0, wxALL | wxEXPAND, 5);

	numPadBtn[5] = new wxButton(this, wxID_ANY, wxT("5"));
	numPad->Add(numPadBtn[5], 0, wxALL | wxEXPAND, 5);

	numPadBtn[6] = new wxButton(this, wxID_ANY, wxT("6"));
	numPad->Add(numPadBtn[6], 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* multDivSizer;
	multDivSizer = new wxBoxSizer(wxHORIZONTAL);

	multBtn = new wxButton(this, wxID_ANY, wxT("×"));
	multDivSizer->Add(multBtn, 0, wxALL | wxEXPAND, 5);

	divBtn = new wxButton(this, wxID_ANY, wxT("÷"));
	multDivSizer->Add(divBtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(multDivSizer, 1, wxEXPAND, 5);

	numPadBtn[1] = new wxButton(this, wxID_ANY, wxT("1"));
	numPad->Add(numPadBtn[1], 0, wxALL | wxEXPAND, 5);

	numPadBtn[2] = new wxButton(this, wxID_ANY, wxT("2"));
	numPad->Add(numPadBtn[2], 0, wxALL | wxEXPAND, 5);

	numPadBtn[3] = new wxButton(this, wxID_ANY, wxT("3"));
	numPad->Add(numPadBtn[3], 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* plusMinSizer;
	plusMinSizer = new wxBoxSizer(wxHORIZONTAL);

	plusBtn = new wxButton(this, wxID_ANY, wxT("+"));
	plusMinSizer->Add(plusBtn, 0, wxALL | wxEXPAND, 5);

	minusBtn = new wxButton(this, wxID_ANY, wxT("-"));
	plusMinSizer->Add(minusBtn, 0, wxALL | wxEXPAND, 5);

	numPad->Add(plusMinSizer, 1, wxEXPAND, 5);

	numPadBtn[0] = new wxButton(this, wxID_ANY, wxT("0"));
	numPad->Add(numPadBtn[0], 0, wxALL | wxEXPAND, 5);

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
	numPadBtn[1]->Bind(wxEVT_BUTTON, &CalculatorFrame::onOneClick, this);
	numPadBtn[2]->Bind(wxEVT_BUTTON, &CalculatorFrame::onTwoClick, this);
	numPadBtn[3]->Bind(wxEVT_BUTTON, &CalculatorFrame::onThreeClick, this);
	numPadBtn[4]->Bind(wxEVT_BUTTON, &CalculatorFrame::onFourClick, this);
	numPadBtn[5]->Bind(wxEVT_BUTTON, &CalculatorFrame::onFiveClick, this);
	numPadBtn[6]->Bind(wxEVT_BUTTON, &CalculatorFrame::onSixClick, this);
	numPadBtn[7]->Bind(wxEVT_BUTTON, &CalculatorFrame::onSevenClick, this);
	numPadBtn[8]->Bind(wxEVT_BUTTON, &CalculatorFrame::onEightClick, this);
	numPadBtn[9]->Bind(wxEVT_BUTTON, &CalculatorFrame::onNineClick, this);
	numPadBtn[0]->Bind(wxEVT_BUTTON, &CalculatorFrame::onZeroClick, this);

	fBracketBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onFBracketClick, this);
	bBracketBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onBBracketClick, this);
	multBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onMultClick, this);
	divBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onDivClick, this);
	plusBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onAddClick, this);
	minusBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onMinClick, this);

	decimalBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onDecClick, this);
	negBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onNegClick, this);

	equalBtn->Bind(wxEVT_BUTTON, &CalculatorFrame::onEqualClick, this);
}

void CalculatorFrame::onOneClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "1");
	appendDigit(1);
}

void CalculatorFrame::onTwoClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "2");
	appendDigit(2);
}

void CalculatorFrame::onThreeClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "3");
	appendDigit(3);
}

void CalculatorFrame::onFourClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "4");
	appendDigit(4);
}

void CalculatorFrame::onFiveClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "5");
	appendDigit(5);
}

void CalculatorFrame::onSixClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "6");
	appendDigit(6);
}

void CalculatorFrame::onSevenClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "7");
	appendDigit(7);
}

void CalculatorFrame::onEightClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "8");
	appendDigit(8);
}

void CalculatorFrame::onNineClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "9");
	appendDigit(9);
}

void CalculatorFrame::onZeroClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "0");
	appendDigit(0);
}

void CalculatorFrame::onFBracketClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + "(");

	// Setup Term
	activeTerms.push_back(new Term());
}

void CalculatorFrame::onBBracketClick(wxCommandEvent& evt) {
	displayText->SetLabelText(displayText->GetLabelText() + ")");

	// Remove Closed Term from active terms
	activeTerms.pop_back();
}

void CalculatorFrame::onMultClick(wxCommandEvent& evt) {
	// Grab Pointer
	Term* subterm_parent;

	// Check if term container of subterms doesn't exists
	if (activeTerms.back()->isParent()) {
		// Setup Term
		if (currentTerm == nullptr) {
			subterm_parent = new Term(false, true, currentNumber);
		}else{
			subterm_parent = new Term(false, true, currentTerm);
		}

		// Append to parent term
		activeTerms.back()->addChild(subterm_parent);

		// Append to activeTerms
		activeTerms.push_back(subterm_parent);
	}else{
		subterm_parent = activeTerms.back();

		// Add Subterm
		if (currentTerm == nullptr) {
			subterm_parent->addSubTerm(currentOperation, currentNumber);
		}
		else {
			subterm_parent->addSubTerm(currentOperation, currentTerm);
		}
	}

	// Update currentOperator
	currentOperation = termMULT;

	// Reset
	currentNumber = 0;
	currentTerm = nullptr;
	decimalPoint = 0;

	// Update Display
	displayText->SetLabelText(displayText->GetLabelText() + "×");
}

void CalculatorFrame::onDivClick(wxCommandEvent& evt) {
	// Grab Pointer
	Term* subterm_parent;

	// Check if term container of subterms doesn't exists
	if (activeTerms.back()->isParent()) {
		// Setup Term
		if (currentTerm == nullptr) {
			subterm_parent = new Term(false, true, currentNumber);
		}
		else {
			subterm_parent = new Term(false, true, currentTerm);
		}

		// Append to parent term
		activeTerms.back()->addChild(subterm_parent);

		// Append to activeTerms
		activeTerms.push_back(subterm_parent);
	}
	else {
		subterm_parent = activeTerms.back();

		// Add Subterm
		if (currentTerm == nullptr) {
			subterm_parent->addSubTerm(currentOperation, currentNumber);
		}
		else {
			subterm_parent->addSubTerm(currentOperation, currentTerm);
		}
	}

	// Update currentOperator
	currentOperation = termDIV;

	// Reset
	currentNumber = 0;
	currentTerm = nullptr;
	decimalPoint = 0;

	// Update Display
	displayText->SetLabelText(displayText->GetLabelText() + "÷");
}

void CalculatorFrame::onAddClick(wxCommandEvent& evt) {
	// MULT and DIV interject
	if (!activeTerms.back()->isParent()) {
		// Add Subterm
		if (currentTerm == nullptr) {
			activeTerms.back()->addSubTerm(currentOperation, currentNumber);
		}
		else {
			activeTerms.back()->addSubTerm(currentOperation, currentTerm);
		}

		// Remove latest activeTerm
		activeTerms.pop_back();

		// Reset
		currentNumber = 0;
		currentTerm = nullptr;
		decimalPoint = 0;
	// Regular
	} else {
		// Append to Parent Term
		if (currentTerm == nullptr) {
			activeTerms.back()->addChild(currentNumber * (positive ? 1 : -1));
			// Reset
			currentNumber = 0;
			decimalPoint = 0;
		} else {
			activeTerms.back()->addChild(currentTerm);
			// Reset
			currentTerm = nullptr;
		}
	}

	// Set for future
	positive = true;

	// Update Display
	displayText->SetLabelText(displayText->GetLabelText() + "+");
}

void CalculatorFrame::onMinClick(wxCommandEvent& evt) {
	// MULT and DIV interject
	if (!activeTerms.back()->isParent()) {
		// Add Subterm
		if (currentTerm == nullptr) {
			activeTerms.back()->addSubTerm(currentOperation, currentNumber);
		}
		else {
			activeTerms.back()->addSubTerm(currentOperation, currentTerm);
		}

		// Remove latest activeTerm
		activeTerms.pop_back();

		// Reset
		currentNumber = 0;
		currentTerm = nullptr;
		decimalPoint = 0;
	// Regular
	} else {
		// Append to Parent Term
		if (currentTerm == nullptr) {
			activeTerms.back()->addChild(currentNumber * (positive ? 1 : -1));
			// Reset
			currentNumber = 0;
			decimalPoint = 0;
		}
		else {
			activeTerms.back()->addChild(currentTerm);
			// Reset
			currentTerm = nullptr;
		}
	}

	// Set for future
	positive = false;

	// Update Display
	displayText->SetLabelText(displayText->GetLabelText() + "-");
}

void CalculatorFrame::onDecClick(wxCommandEvent& evt) {
	// Start Countdown if not already
	if (decimalPoint == 0) {
		decimalPoint = 1;

		// Update Display
		displayText->SetLabelText(displayText->GetLabelText() + ".");
	}
}

void CalculatorFrame::onNegClick(wxCommandEvent& evt) {
	// Only Allow this to be entered at beginning of decimals and terms
	if (currentNumber == 0) {
		displayText->SetLabelText(displayText->GetLabelText() + "-");
	
		positive = !positive;
	}
}

void CalculatorFrame::onEqualClick(wxCommandEvent& evt) {
	// MULT and DIV interject
	if (!activeTerms.back()->isParent()) {
		// Add Subterm
		if (currentTerm == nullptr) {
			activeTerms.back()->addSubTerm(currentOperation, currentNumber);
		} else {
			activeTerms.back()->addSubTerm(currentOperation, currentTerm);
		}

		// Remove latest activeTerm
		activeTerms.pop_back();
	// Regular
	} else {
		// Append to Parent Term
		if (currentTerm == nullptr) {
			activeTerms.back()->addChild(currentNumber * (positive ? 1 : -1));
		} else {
			activeTerms.back()->addChild(currentTerm);
		}
	}

	// Catch Unclosed terms
	if (activeTerms.size() > 1) {
		wxLogMessage("Error: Terms still open.");
		return;
	}
	
	// Reset Trackers
	wxLogStatus("Current Number: %f", activeTerms.front()->calculate());
	currentNumber = 0;
	currentTerm = nullptr;
	currentOperation = termNULL;
	decimalPoint = 0;
	positive = true;
	activeTerms.front()->clear();

	// Update Display
	displayText->SetLabelText("");
}

void CalculatorFrame::appendDigit(unsigned int digit) {
	// Add Digit to currentNumber
	currentNumber = currentNumber * (decimalPoint == 0 ? 10 : 1) + digit / pow(10, decimalPoint);

	// Adjust decimalPoint if needed
	if (decimalPoint > 0)
		decimalPoint++;
}

CalculatorFrame::~CalculatorFrame() {
	// Free Terms
	for (vector<Term*>::iterator i = activeTerms.begin(); i != activeTerms.end(); ++i) {
		delete* i;
	}
}