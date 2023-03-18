#pragma once
#include <wx/wx.h>

class CalculatorFrame : public wxFrame {

public:
	CalculatorFrame();

protected:
	// Display Objects
	wxPanel* displayPanel;
	wxStaticText* displayText;

	// Number Buttons
	wxButton* numPadBtn[10];

	// Function Buttons
	wxButton* fBracketBtn;
	wxButton* bBracketBtn;
	wxButton* multBtn;
	wxButton* divBtn;
	wxButton* plusBtn;
	wxButton* minusBtn;
	wxButton* decimalBtn;
	wxButton* negBtn;
	wxButton* equalBtn;
	
private:
	// Number Button Events
	void onOneClick(wxCommandEvent& evt);
	void onTwoClick(wxCommandEvent& evt);
	void onThreeClick(wxCommandEvent& evt);
	void onFourClick(wxCommandEvent& evt);
	void onFiveClick(wxCommandEvent& evt);
	void onSixClick(wxCommandEvent& evt);
	void onSevenClick(wxCommandEvent& evt);
	void onEightClick(wxCommandEvent& evt);
	void onNineClick(wxCommandEvent& evt);
	void onZeroClick(wxCommandEvent& evt);

	// Function Button Events
	void onFBracketClick(wxCommandEvent& evt);
	void onBBracketClick(wxCommandEvent& evt);
	void onMultClick(wxCommandEvent& evt);
	void onDivClick(wxCommandEvent& evt);
	void onAddClick(wxCommandEvent& evt);
	void onMinClick(wxCommandEvent& evt);
	void onDecClick(wxCommandEvent& evt);
	void onNegClick(wxCommandEvent& evt);
	void onEqualClick(wxCommandEvent& evt);

};

