/*
 * inpre.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#include "inpre.h"
#include "inpost.h"
#include "stack.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "stack_int.h"
#include<math.h>
using namespace std;

void inpre :: infix_to_prefix(string arr,stacks s)
{
	int len=arr.length(),k=0;

	string ans;

	inpost post;

	for(int i=len-1;i>=0;i--)
	{
	   char x=arr[i];

		if( (x>='A' && x<='Z') || (x>='a' && x<='z') )
		{
			ans[k++]=x;
		}

		else if(x==')')
			s.push(x);

		else if(x=='(')
		{
			while(s.tope() != ')')
			{
				ans[k++]=s.pop();
			}

			s.pop();

		}

		else
		{
			//cout<<"IGI\n";

			if(s.isempty())
			{
				s.push(x);
			}


			else
			{
				if(post.right_assosciativity(x))
				{
					while(post.priority(s.tope()) >= post.priority(x) )
					{
						ans[k++]=s.pop();

					}
				}

				else
				{
					while(post.priority(s.tope()) > post.priority(x) )
					{
						ans[k++]=s.pop();

					}
				}

				s.push(x);
			}
		}
	}

	while(!s.isempty())
		ans[k++]=s.pop();


	for(int i=k-1;i>=0;i--)
		cout<<""<<ans[i];

	cout<<endl;

}

int inpre :: prefix_eval(string arr,stack_int s)
{
	int len=arr.length();

	for(int i=len-1;i>=0;i--)
	{
		char x=arr[i];

		if(x>='0' && x<='9')
			s.push(x-'0');

		else
		{
			int op1=s.pop();
			int op2=s.pop();
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



