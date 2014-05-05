#include "operator.h"
#include "tokens.h"
#include "node.h"
#include "runtimeStack.h"
#include "id.h"
#include "number.h"
#include <iostream>

using namespace std;

void  Operator::setLeft(Expr* ptr) {
	if (left == NULL) left = ptr;	
	else left->setLeft(ptr);
}

double Operator::execute(RuntimeStack* stack) {

    Node* n = getLeft();

    Id* id;
    Number* num;
    double left, right;

    // capture the left side

    switch ( n->getKind() ) {

    case ID:     

        id = (Id *) n;

        // TODO: Check for existance of id
        left = stack->symbolTable[ id->getName() ];

    break;

    case NUMBER:

        num = (Number *) n;
        left = num->getValue();

    break;


    }

    cout << "Value of left: " << left << endl;

    // capture the right side

    n = getRight();

    switch ( n->getKind() ) {

    case ID:    

        id = (Id *) n;

        // TODO: Check for existance of id
        right = stack->symbolTable[ id->getName() ];

    break;

    case NUMBER:

        num = (Number *) n;
        right = num->getValue();

    break;


    }

    cout << "Value of right: " << right << endl;

    // finally, figure out what to do here.

    double result;

    switch ( this->getKind() ) {

    case PLUS:

        result = left + right;

    break;

    case MINUS:

        result = left - right;

    break;

    }

    cout << "After operator: " << result << endl;

    return result;


};
