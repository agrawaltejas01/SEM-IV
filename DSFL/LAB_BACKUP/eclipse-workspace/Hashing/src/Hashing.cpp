//============================================================================
// Name        : Hashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "student.h"
#include "replace.h"
#include "no_replace.h"
using namespace std;

int main()
{
	student s[10];
	s[0].create(s);

	//cout<<s[0].n<<endl;

	//s[0].display(s);

	replace r(s[0].n);
	//cout<<"IGI\n\n";
	r.insert(s);
	//cout<<"IGI\n\n";
	r.display();
	r.search(105);

	return 0;
}
