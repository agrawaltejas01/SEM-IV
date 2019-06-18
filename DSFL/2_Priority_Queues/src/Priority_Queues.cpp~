
                  //PRIORITY_QUEUE.cpp

/* Name        : Tejas Agrawal
/ Author      : 2002          */



#include <iostream>
#include<stdlib.h>
#include "queues.h"
using namespace std;

int main()
{

	queues q;

	int ch;
	do
	{
		cout<<"\n\n---------Menu-----------\n\n";
		cout<<"\t\t1.Add Patient\n\t\t2.Display List\n\t\t3.Choose patient for Treatment\n\t\t"
				"4.Exit\n\n\t\t";

		cout<<"Enter Your Choice : ";
		cin>>ch;
		cout<<endl;

		switch(ch)
		{
			case 1 :	q.enqueue ();
						break;
			case 2 :    q.display();
						break;
			case 3 :    q.dequeue();
						break;
			case 4 :    exit(0);
					    break;
			default:    cout<<"Invalid Choice Entered\n\n";
						break;
		}
	}
	while(1);

	return 0;
}
