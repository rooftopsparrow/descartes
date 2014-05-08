#include <iostream>

#include "operator.h"
#include "number.h"
#include "id.h"
#include "tokens.h"
#include "runtimeStack.h"

using namespace std;

void  Operator::setLeft(Expr* ptr) {
	if (left == NULL) left = ptr;	
	else left->setLeft(ptr);
};

double Operator::execute(RuntimeStack * stack, Expr * n) {

    double result;
    Number * num;
    Id * id;
    Operator * op;

    switch ( n->getKind() ) {

    case ID:     

        // TODO: Check for existance of id
        id = (Id *) n;
        cout << "ID: " << id->getName() << endl;
        result = stack->symbolTable[ id->getName() ];

    break;

    case NUMBER:

        num = (Number *) n;
        cout << "NUMBER: " << num->getValue() << endl;
        result = num->getValue();

    break;

    case PLUS:
    case MINUS:
    case TIMES:
    case DIV:

        op = (Operator *) n;
        result = n->execute(stack);

    break;

    default:

        cout << "UNKNOWN TYPE: " << n->getKind() << endl;
        result = 0.0;

    break;

    };


    return result;


};

double Operator::execute(RuntimeStack * stack) {


    double left, right, finalResult;

    left = this->execute(stack, this->getLeft());
    right = this->execute(stack, this->getRight());

    switch ( this->getKind() ) {

    case PLUS:

        cout << "OPPERATOR: (+)" << endl;
        finalResult = left + right;

    break;

    case MINUS:

        cout << "OPPERATOR: (-)" << endl;
        finalResult = left - right;

    break;

    case TIMES:

        cout << "OPPERATOR: (*)" << endl;
        finalResult = left * right;

    break;

    case DIV:

        cout << "OPPERATOR: (/)" << endl;
        finalResult = left / right;

    break;


    }

    cout << "After operator: " << finalResult << endl;

    return finalResult;


};
