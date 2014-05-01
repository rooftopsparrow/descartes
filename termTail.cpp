#include <stdlib.h>
#include "termTail.h"

Expr * TermTail::parse(Scanner &scan) {
	Expr		*subtree;				//the expression subtree
	Expr		*rhs;					//lhs of the above subtree
	Term		*t	= new Term();		
	TermTail	*tt	= new TermTail();
	
	if (scan.getCurrSymb() == PLUS || scan.getCurrSymb() == MINUS) {	

		Operator * op = new Operator(scan.getCurrSymb());
		scan.nextToken();
		rhs	= t->parse(scan);
		op->setRight(rhs);
		subtree = tt->parse(scan);

		if (subtree != NULL) {

			subtree->setLeft(op);
			return subtree;

		}

		return op;
	} 

	return NULL;
}
