/*
 * inpost.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#include "inpost.h"
#include "stack.h"
#include <string>
#include<math.h>
#include <stdexcept>
#include <iostream>
#include "stack_int.h"
using namespace std;


int inpost ::  priority(char x)
{
	if(x=='^')
		return 4;

	else if(x=='/' || x=='*')
		return 3;

	else if(x=='+' || x=='-')
		return 2;


	else return -1;

}

int inpost :: right_assosciativity(char x)
{
	if(x=='^')
		return 1;

	else
		return 0;
}

void inpost :: infix_to_postfix(string arr, stacks s)
{
	int len=arr.length(),k=0;

		for(int i=0;i<len;i++)
		{
			char x=arr[i];

			if( (x>='A' && x<='Z') || (x>='a' && x<='z') )
			{
				cout<<""<<x;
			}

			else if(x=='(')
						s.push(x);

			else if(x==')')
			{
				while(s.tope() != '(')
				{
					cout<<""<<s.pop();
				}

				s.pop();

			}

			else
			{
				if(s.isempty())
					s.push(x);

				else
				{
					if(right_assosciativity(x))
					{
						while(priority(s.tope()) > priority(x) )
						{
							cout<<""<<s.pop();

						}
					}

					else
					{
						while(priority(s.tope()) >= priority(x) )
						{
							cout<<""<<s.pop();

						}
					}

					s.push(x);
				}
			}
		}

		while(!s.isempty())
				{
						cout<<""<<s.pop();
				}

		cout<<endl;
}

int inpost :: postfix_eval(string arr,stack_int s)
{
	int len=arr.length();

	for(int i=0;i<len;i++)
	{
		char x=arr[i];

		if(x>='0' && x<='9')
			s.push(x-'0');

		else
		{
			int op2=s.pop();
			int op1=s.pop();
			int res=0;

			switch(x)
			{
				case '*':
					res=op1*op2;
					break;

				case '+':
					res=op1+op2;
					break;

				case '-':
					res=op1-op2;
					break;

				case '/':
					res=op1/op2;
					break;

				case '^':
					res=pow(op1,op2);
					break;
			}

			s.push(res);
		}
	}

	return s.pop();
}

