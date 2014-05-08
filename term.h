/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef TERM_H
#define TERM_H

#include "scanner.h"
#include "expr.h"
#include "runtimeStack.h"

class Term {
    public:
        Term() {};
        Expr * parse(Scanner &);	
};
#endif
