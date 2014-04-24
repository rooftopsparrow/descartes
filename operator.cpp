#include "operator.h"

void  Operator::setLeft(Expr* ptr) {
	if (left == NULL)	left = ptr;	
	else				left->setLeft(ptr);
}
