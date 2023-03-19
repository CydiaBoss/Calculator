#include "Term.h"
#include <stdexcept>
#include <vector>

using namespace std;

Term::Term(bool parent, bool positive, Term firstChild) {

}

Term::Term(bool parent, bool positive, double firstChild) {

}

void Term::addSubTerm(unsigned int operation, Term subterm) {

}

void Term::addSubTerm(unsigned int operation, double subterm) {

}

void Term::addChild(Term child) {

}

void Term::addChild(double child) {

}

unsigned int Term::length() {
	return constants.size() + terms.size();
}

double Term::calculate() {

	// Term Info
	double value;

	// Attempt to Look for value in constants map
	try {
		value = constants.at(0);
	}
	// Conduct math from Term
	catch (const std::out_of_range&) {
		value = terms.at(0).calculate();
	}

	// Start Calculation
	for (int i = 1; i < length(); i++) {
		// Parent Mode
		if (parent) {
			try {
				value += constants.at(i);
			} catch (const std::out_of_range&) {
				// Conduct math
				value += terms.at(i).calculate();
			}
		}

		// SubTerm Mode
		else {
			try {
				switch (operations[i]) {
				case MULT:
					value *= constants.at(i);
					break;
				case DIV:
					value /= constants.at(i);
					break;
				default:
					break;
				}
			}
			catch (const std::out_of_range&) {
				// Conduct Math
				switch (operations[i]) {
				case MULT:
					value *= terms.at(i).calculate();
					break;
				case DIV:
					value /= terms.at(i).calculate();
					break;
				default:
					break;
				}
			}
		}
	}

	return value * (positive ? 1 : -1);
}

Term::~Term() {
	delete& parent;
	delete& positive;
	delete& operations;
	delete& constants;
	delete& terms;
}