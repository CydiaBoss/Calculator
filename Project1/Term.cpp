#include "Term.h"
#include <stdexcept>
#include <vector>

using namespace std;

Term::Term(bool positive, double constant) {
	this->positive = positive;
	this->parent = false;
	this->constants = {
		{0, constant},
	};

	// Empty
	this->operations = {};
	this->terms = {};
}

Term::Term(vector<char> operations, map<int, Term> terms, map<int, double> constants) {
	this->positive = true;
	this->operations = operations;
	this->terms = terms;
	this->constants = constants;
}

double Term::calculate() {
	// Start Math
	double total = 0;
	int i;
	for (i = 0; i < this->constants.size() + this->terms.size(); i++) {
		// Attempt to Look for value in constants map
		try {
			total += constants.at(i);
		} catch (const std::out_of_range&) {
			
		}
	}

	// Add Sign based on 
}

Term::~Term() {}