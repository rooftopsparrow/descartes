/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef FACTOR_H
#define FACTOR_H

#include "scanner.h"
#include "expr.h"
#include "runtimeStack.h"

class Factor {
    public:
	    Factor() { };
		Expr * parse(Scanner &);	
        double execute(RuntimeStack *);    
};
#endif
