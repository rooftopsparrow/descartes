/*	For nodes representing identifiers
**  Written by Aaron Gordon
*/
#ifndef ID_H
#define ID_H
#include "tokens.h"
#include "expr.h"

using namespace std;

class Id : public Expr {

	private:

    string  printname;

	public:

        Id(string s) {
            nodekind = ID;
            printname = s;
        };

        string getName() {
            return printname;
        };
};

#endif
