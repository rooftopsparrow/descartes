/*	For nodes representing expressions
**  Written by Aaron Gordon
*/
#ifndef EXPR_H
#define EXPR_H

#include  "node.h"
#include  "scanner.h"
#include "runtimeStack.h"
#include  <iostream>

class Expr : public Node {

    public:

    	Expr (){};
    	Expr * parse(Scanner &scan);
    	virtual void setLeft(Expr *) {
            std::cout << "expr.setLeft" << std::endl;
        };
        virtual double execute (RuntimeStack* stack) {
            std::cout << "expr.execute" << std::endl; 
            return 0.0;
        }
};

#endif
