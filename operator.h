/*	For nodes containing operators such as +, -, *, /
**  Written by Aaron Gordon
*/
#ifndef OPERATOR_h
#define OPERATOR_h

#include "expr.h"
#include <stdlib.h>

class Operator : public  Expr {
    Expr *left;
    Expr *right;

    public:

        Operator() {
            left = NULL;
        };

        Operator(int type) {
            left = NULL;
            nodekind = type;
        };

        Expr* getRight() {
            return right;
        };

        Expr* getLeft() {
            return left;
        };

        void setRight(Expr* ptr) {
            right = ptr;
        };

        void setLeft(Expr* ptr);

        double execute(RuntimeStack* stack);

};
#endif
