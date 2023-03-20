#include "Term.h"
#include <stdexcept>
#include <vector>

using namespace std;

Term::Term() {
	this->parent = true;
	this->positive = true;

	// Setup Maps
	this->terms = {};
	this->constants = {};

	// Setup Operations
	this->operations = {};
}

Term::Term(bool parent, bool positive, Term firstChild) {
	this->parent = parent;
	this->positive = positive;

	// Setup Maps
	this->terms = {
		{0, firstChild}
	};
	this->constants = {};

	// Setup Operations
	this->operations = {};
}

Term::Term(bool parent, bool positive, double firstChild) {
	this->parent = parent;
	this->positive = positive;

	// Setup Maps
	this->terms = {};
	this->constants = {
		{0, firstChild}
	};

	// Setup Operations
	this->operations = {};
}

bool Term::isParent() {
	return parent;
}

bool Term::isPositive() {
	return positive;
}

void Term::setPositive(bool positive) {
	this->positive = positive;
}

void Term::addSubTerm(unsigned int operation, Term subterm) {
	// Add Operation
	operations.push_back(operation);

	// Add Term
	terms[length()] = subterm;
}

void Term::addSubTerm(unsigned int operation, double subterm) {
	// Add Operation
	operations.push_back(operation);

	// Add constant
	constants[length()] = subterm;
}

void Term::addChild(Term child) {
	// Add Term
	terms[length()] = child;
}

void Term::addChild(double child) {
	// Add constant
	constants[length()] = child;
}

unsigned int Term::length() {
	return constants.size() + terms.size();
}

void Term::clear() {
	constants.clear();
	terms.clear();
	operations.clear();
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
	for (unsigned int i = 1; i < length(); i++) {
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