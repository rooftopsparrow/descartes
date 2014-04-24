/*	For nodes representing identifiers
**  Written by Aaron Gordon
*/
#ifndef ID_H
#define ID_H
#include "tokens.h"
#include "expr.h"

class Id : public Expr {
		 private: std::string  printname; 	//the string representation of the identifier
		 public: Id(std::string s) {nodekind = ID; printname = s;};			//constructor
		 		 std::string getName() { return printname;};	//accessor method
};
#endif
