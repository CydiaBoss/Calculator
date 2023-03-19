#include <map>
#include <vector>

#pragma once

using namespace std;

/// <summary>
/// Term within a mathematical equation
/// </summary>
class Term {

private:
	/// <summary>
	/// Whether a term is a parent to child terms; indicates that
	/// the term is equivalent to a bracketed sub equation with addition and
	/// subtraction
	/// </summary>
	bool parent;

	/// <summary>
	/// Whether a term is positive (+)
	/// </summary>
	bool positive;

	/// <summary>
	/// For subterm mode; operations to complete between subterms
	/// </summary>
	vector<unsigned int> operations;

	/// <summary>
	/// Constants under a term
	/// </summary>
	map<unsigned int, double> constants;

	/// <summary>
	/// Terms under a term; child terms for parents, subterms for terms
	/// </summary>
	map<unsigned int, Term> terms;

public:

	enum operationIDS {
		// Multipication
		MULT = 1,

		// Division
		DIV = 2,
	};

	/// <summary>
	/// Creates a term
	/// </summary>
	/// <param name="parent">-> determine term type</param>
	/// <param name="positive">-> sign of the term</param>
	/// <param name="firstChild">-> first subterm or child</param>
	Term(bool parent, bool positive, Term firstChild);

	/// <summary>
	/// Creates a term
	/// </summary>
	/// <param name="parent">-> determine term type</param>
	/// <param name="positive">-> sign of the term</param>
	/// <param name="firstChild">-> sign of the subterm or child</param>
	Term(bool parent, bool positive, double firstChild);

	/// <summary>
	/// Add a Term subterm
	/// </summary>
	/// <param name="operation">-> operation to apply between subterm</param>
	/// <param name="subterm">-> Term subterm</param>
	void addSubTerm(unsigned int operation, Term subterm);

	/// <summary>
	/// Add a constant subterm
	/// </summary>
	/// <param name="operation">-> operation to apply between subterm</param>
	/// <param name="subterm">-> constant subterm</param>
	void addSubTerm(unsigned int operation, double subterm);

	/// <summary>
	/// Add a child term
	/// </summary>
	/// <param name="child">-> child Term</param>
	void addChild(Term child);

	/// <summary>
	/// Add a child constant
	/// </summary>
	/// <param name="subterm">-> child constant</param>
	void addChild(double child);

	/// <summary>
	/// Number of subterms of children
	/// </summary>
	/// <returns>size of Term</returns>
	unsigned int length();

	/// <summary>
	/// Calculate a term
	/// </summary>
	/// <returns>value of term</returns>
	double calculate();

	~Term();

};

