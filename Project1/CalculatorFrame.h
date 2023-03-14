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
	wxButton* oneBtn;
	wxButton* twoBtn;
	wxButton* threeBtn;
	wxButton* fourBtn;
	wxButton* fiveBtn;
	wxButton* sixBtn;
	wxButton* sevenBtn;
	wxButton* eightBtn;
	wxButton* nineBtn;
	wxButton* zeroBtn;

	// Function Buttons
	wxButton* fBracketBtn;
	wxButton* bBracketBtn;
	wxButton* multbtn;
	wxButton* divbtn;
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

};

