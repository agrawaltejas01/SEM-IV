
                        //INPRE.h
                        

/*
 * inpre.h
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#ifndef INPRE_H_
#define INPRE_H_
#include <string>
#include "stack.h"
#include <iostream>
#include <stdexcept>
#include "stack_int.h"
using namespace std;


class inpre
{

public:
	void infix_to_prefix(string arr,stacks s);
	int prefix_eval(string arr,stack_int p);
};

#endif /* INPRE_H_ */
