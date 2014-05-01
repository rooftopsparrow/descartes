/*	For nodes representing arithmetic expressions
**  Written by Aaron Gordon
*/

#include  <iostream>
#include  "expr.h"
#include  "operator.h"
#include  "term.h"
#include  "termTail.h"
#include  <stdlib.h>

Expr * Expr::parse(Scanner &scan){  
	Expr *subtree;
	Expr *lhs;

	Term *t	= new Term();
	TermTail *tt = new TermTail();

	lhs	= t->parse(scan);
	subtree = tt->parse(scan);

	if (subtree == NULL) return lhs;

	else {
		subtree->setLeft(lhs);
		return subtree;
	}
};
