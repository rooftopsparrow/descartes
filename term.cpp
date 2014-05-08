#include <stdlib.h>
#include <iostream>
#include "term.h"
#include "runtimeStack.h"
#include "factor.h"
#include "factorTail.h"

using namespace std;

Expr * Term::parse(Scanner &scan) {

	Expr *subtree; //the expression subtree
	Expr *lhs; //lhs of the above subtree

	Factor *f = new Factor(); //from the grammar
	FactorTail *ft = new FactorTail(); //from the grammar

	lhs	= f->parse(scan); //get the factor
	subtree = ft->parse(scan); //get the factor-tail

	if (subtree == NULL) return lhs;
	else {
		subtree->setLeft(lhs);
		return subtree;
	}
};
