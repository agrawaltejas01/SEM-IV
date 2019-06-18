
                        //EXPRESSION_TREE.cpp


/*
 Name        : Tejas Agrawal
 Roll No.    : 2002
*/

#include "tree.h"
#include<string>
#include<stack>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

int main()
{

	tree t;
		string s;

		node *root;

	do
		{
			int ch,c;
			cout<<"-----------------------MENU---------------------------\n";

			cout<<"\t\t1.Create a Tree\n\t\t"
					"2.Recursive Traversal\n\t\t"
					"3.Non-Recursive Traversal\n\t\t"
					"4.Exit\n\n";

			cout<<"Enter Choice : ";
			cin>>ch;
			cout<<endl;

			switch(ch)
			{
				case 1:
				{

					cout<<"\n\n\t1.Postfix Expression\n\t2.Prefix Expression\n\n";
					cout<<"Enter Choice : ";
					cin>>c;
					cout<<endl;

					switch(c)
					{
						case 1 : cout<<"Enter a postfix expression : ";
								cin>>s;
								cout<<endl;

								cout<<"Tree Created !!!\n";
								t.construct_tree_postorder(s);
								break;

						case 2 : cout<<"Enter a prefix expression : ";
								cin>>s;
								cout<<endl;

								cout<<"Tree Created !!!\n";
								t.construct_tree_preorder(s);
								break;
					}

					break;

				}

				case 2:
				{
					cout<<"\n\n\t1.Recurssive Inorder\n\t\t2.Recurssive Postorder\n\t\t"
							"3.Recurssive Preorder\n\n";
					cout<<"Enter Choice : ";
					cin>>c;
					cout<<endl;

					switch(c)
					{
						case 1 : cout<<"Inorder Traversal is : ";
								 t.inorder(t.root);
								 cout<<endl<<endl;
								 break;

						case 2 : cout<<"Postorder Traversal is : ";
								 t.postorder(t.root);
								 cout<<endl<<endl;
								 break;

						case 3 : cout<<"Preorder Traversal is : ";
								 t.preorder(t.root);
								 cout<<endl<<endl;
								 break;
					}

					break;
				}

				case 3:
				{
					cout<<"\n\n\t1.Non-Recurssive Inorder\n\t\t2.Non-Recurssive Postorder\n\t\t"
							"3.Non-Recurssive Preorder\n\n";
					cout<<"Enter Choice : ";
					cin>>c;
					cout<<endl;

					switch(c)
					{
						case 1 : cout<<"Inorder Traversal is : ";
								 t.inorder_non_recurs(t.root);
								 cout<<endl<<endl;
								 break;

						case 2 : cout<<"Postorder Traversal is : ";
								 t.postrder_non_recurs(t.root);
								 cout<<endl<<endl;
								 break;

						case 3 : cout<<"Preorder Traversal is : ";
								 t.preorder_non_recurs(t.root);
								 cout<<endl<<endl;
								 break;
					}

					break;
				}

				case 4:
				{
					exit(0);
					break;
				}

			}

		}
		while(1);

	return 0;
}
