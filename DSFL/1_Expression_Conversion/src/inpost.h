
                        //INPOST.h
/*
 * inpost.h
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#ifndef INPOST_H_
#define INPOST_H_
#include "stack.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "stack_int.h"
using namespace std;
class inpost
{

public:
		int isoperator(char x);
		int priority(char x);
		int right_assosciativity(char x);

		void infix_to_postfix(string arr,stacks s);
		int postfix_eval(string arr,stack_int p);

};

#endif /* INPOST_H_ */
