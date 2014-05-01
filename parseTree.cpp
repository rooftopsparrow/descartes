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
    map<string, double> symbolTable;

    // Classes we need
    Number *num;
    Operator *op;

    cout << "\n\n\nParseTree::executing" << endl;

    while (curr != NULL ) {

        switch( curr->getKind() ) {

            case BECOMES:

                cout << "assign-stmt : ID BECOMES expr" << endl; 
                Becomes  *be = (Becomes *) curr;
                Node *n = be->getLHS();
                Id  *id = (Id *) n;

                // Add to symbol table if it doesn't exist
                if ( symbolTable.count( id->getName() ) == 0 ) symbolTable[ id->getName() ]; 

                cout <<  id->getName()  << "  := " ;
                n = be->getRHS();

                // figure out what we have as the expression
                // on the right hand side
                switch ( n->getKind() ) {

                    case NUMBER:
                    {
                        num = (Number *) n;
                        symbolTable[ id->getName() ] = num->getValue();
                        cout << num->getValue();
                    }
                    break;

                    case ID:
                    {

                        Id *fromId = (Id *) n;
                        if ( symbolTable.count( fromId->getName() ) == 0 ) new Error(99, " Assignment to undefined variable");
                        symbolTable[ id->getName() ] = symbolTable[ fromId->getName() ];
                        cout << fromId->getName();

                    }
                    break;

                    case PLUS:
                    case MINUS:
                    case DIV:
                    case TIMES:
                    {

                        op = (Operator *) n;


                    }
                    break;

                    default:
                    {

                        cout << "  OTHER  ";

                    }
                    break;

                } 

                cout << endl;

            break;

            }

                curr = curr->getNext();

    }

    cout << " -- Symbol Table -- \n-------------------\n";

    std::map< string, double >::const_iterator iter;

    for ( iter = symbolTable.begin(); iter != symbolTable.end(); ++iter ) {
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
