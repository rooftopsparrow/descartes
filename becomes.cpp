/*	For nodes representing assignment statements
**  Written by Aaron Gordon
*/

#include "tokens.h"
#include "becomes.h"
#include "node.h"
#include "number.h"
#include "operator.h"
#include "runtimeStack.h"
#include "error.h"
#include <iostream>

using namespace std;

void  Becomes::assignment(Scanner &scan) {	//parses assignment stmt

	Expr  *ex = new Expr();
	string variable = scan.getCurrName();
	Id *id = new Id(variable);
	setLHS(id);
	scan.nextToken();

	if (scan.getCurrSymb() != BECOMES) {
		string msg  = "Becomes::assignment:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-71, msg);
	}

	scan.nextToken();
	rhs = ex->parse(scan);
}

void Becomes::execute(RuntimeStack* stack) {

	// Grab the left-hand side of the tree
	// and make it an ID

    Node *n = getLHS();
    Id  *id = (Id *) n;

    cout <<  id->getName()  << "  := " ;

    // Get the right hand side and 
    // deterimine what it is

    Number* num;
    Id* fromId;
    Operator* op;

    n = getRHS();

	switch ( n->getKind() ) {

    case NUMBER:

        num = (Number *) n;
        stack->symbolTable[ id->getName() ] = num->getValue();
        cout << num->getValue();
       
    break;

    case ID:

        fromId = (Id *) n;
        // TODO: check that id exists
        // if ( symbolTable.count( fromId ) == 0 ) new Error(99, " Assignment to undefined variable");
        stack->symbolTable[ id->getName() ] = stack->symbolTable[ fromId->getName() ];

        cout << fromId->getName();
        cout << " # => " << stack->symbolTable[ fromId->getName() ] << endl;

    break;

    case PLUS:
    case MINUS:
    case DIV:
    case TIMES:

        op = (Operator *) n;


    break;

    default:

        cout << "  OTHER  ";

    break;

    } 

    cout << endl;

};
