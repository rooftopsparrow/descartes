/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef TERMTAIL_h
#define TERMTAIL_h

#include "scanner.h"
#include "expr.h"
#include "runtimeStack.h"

class TermTail {
    public:
    	TermTail() {};
    	Expr * parse(Scanner &);	
        double execute(RuntimeStack *);
};

#endif
