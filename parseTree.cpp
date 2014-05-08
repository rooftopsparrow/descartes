/*  To build the parse tree for Descarte
 *  Written by Aaron Gordon
 */

//-------------------------

#include    <stdio.h>
#include    <iostream>
#include    <string>
#include    <map>

#include    "tokens.h"
#include    "node.h"
#include    "parseTree.h"
#include    "becomes.h"
#include    "id.h"
#include    "error.h"
#include    "operator.h"
#include    "number.h"

using namespace std;

ParseTree::ParseTree(){
    root = NULL;
}

void ParseTree::init(string fname) {
    scan.init(fname);
}

void ParseTree::execute(){

    StmtNode *curr = root;
    RuntimeStack * stack = new RuntimeStack();


    cout << "\n\n\nParseTree::executing" << endl;

    while (curr != NULL ) {

        switch( curr->getKind() ) {

        case BECOMES:

            cout << "assign-stmt : ID BECOMES expr" << endl; 
            Becomes  *be = (Becomes *) curr;

            be->execute(stack);
                
        break;

        }

        curr = curr->getNext();

    }

    cout << " -- Symbol Table -- \n-------------------\n";

    std::map<string, double>::const_iterator iter;

    for ( iter = stack->symbolTable.begin(); iter != stack->symbolTable.end(); ++iter ) {
        cout << iter->first << '\t' << iter->second << '\n';
    }

    cout << endl;

}

/* prog : stmt stmt-tail */
void ParseTree::build( ) {
    stmt(root); //root points to first statement node after call
    stmtTail(*root); //pass in node where rest of pgm is to be attached

    cout << "time to end, token is " << scan.getCurrSymb() << endl;

    if (scan.getCurrSymb() != PERIOD) new Error(6, " PERIOD expected");
}

void ParseTree::stmtTail (StmtNode &current) {
/*  Current is the end of a chain of statements.  If there are more
    statements, tack them on the end. */
    StmtNode *nextStmt;
    if (scan.getCurrSymb() == SEMICOLON)  { // stmt-tail : SEMICOLON stmt stmt-tail
      cout << "stmtTail: " << endl;
      scan.nextToken();
      stmt(nextStmt);               //create the statement node for the next statement
      current.setNext(nextStmt);    //attach it to the list of nodes
      stmtTail(*nextStmt);          //build up the rest of the program
    } // else stmt-tail is empty; do nothing
}


// Create a statement node and have current point to it
void ParseTree::stmt (StmtNode *&current) {

    int symb = scan.getCurrSymb();
    switch (symb) {

    case ID: // stmt : ID := expr
        Becomes *be;
        be = new Becomes();
        current = be;
        be->assignment(scan);  //find an assignment statement
    break;

    default:
             string msg2="Unrecognized statement: ";
             new Error(4,msg2.append( scan.getCurrName()));
    }
    
}
