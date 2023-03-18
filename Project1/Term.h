#include <map>
#include <vector>

#pragma once

using namespace std;

class Term {

private:
	bool parent;
	bool positive;
	vector<char> operations;
	map<int, double> constants;
	map<int, Term> terms;

public:
	Term(bool positive, double constant);
	Term(char expr);
	Term(vector<char> operations, map<int, Term> terms, map<int, double> constants);
	~Term();
	void addTerm(char operation, Term child);
	void addTerm(char operation, double child);
	double calculate();

};

