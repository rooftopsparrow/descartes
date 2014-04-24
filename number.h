/*  For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef NUMBER_h
#define NUMBER_h

#include "tokens.h"
#include "expr.h"
class Number : public Expr {
     private: double       value;               //The number
     public: Number(double d) {nodekind = NUMBER; value = d;};      //constructor
     public: double getValue() {return value;}; //accessor method
};
#endif
