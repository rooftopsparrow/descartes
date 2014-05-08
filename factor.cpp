#include <stdlib.h>
#include "factor.h"
#include "operator.h"
#include "id.h"
#include "number.h"
#include "error.h"
#include <iostream>

using namespace std;

Expr * Factor::parse(Scanner &scan) {

	switch (scan.getCurrSymb() ) {
		case ID: // factor  :  ID
		{
			Id   *id = new Id(scan.getCurrName());
			scan.nextToken();
			return  id;
		}
		case NUMBER: // factor  :  CONST
		{
			Number *num = new Number(scan.getCurrValue());
			scan.nextToken();
			return num;
		}
/* Negative numbers
		case MINUS: // factor 	: - factor (urnary)
		{
			scan.nextToken();
			Operator neg = Operator(TIMES);
			Number n = Number(-1);
			Number * num = &n;
			neg->setLeft(num);
			Factor f;
			Expr * exptr = f.parse(scan);
			neg->setRight(exptr);
			scan.nextToken();
			return &neg;
		}
*/
		case OPEN:
		{
			scan.nextToken();
			Expr  ex;
			Expr  *exptr = ex.parse(scan);
			scan.nextToken();
			return exptr;
		}
		default:

			cerr << 
				"Factor::parse  Unknown expression,  currSymb = "
				<< scan.getCurrSymb() << endl;
			new Error(3);

		break;
	}

	return NULL;
}
