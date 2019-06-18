#include<bits/stdc++.h>
using namespace std;

int isoperator(char x)
{
      if( ( (x== '+') || (x == '-') || (x == '*') || (x == '/') || (x == '^') ) )
            return 1;
      
      else
            return 0;
}

int read(string s)
{
      int len=s.length();      
      
      for(int i=0;i<len-1;i++)
      {
            if(s[i]=='(')
            {
                  if (! (s[i+1] != '(' || !isalnum(s[i+1]) ))
                  {
                        cout<<"Invalid !!!\n\n";
                        return 0;
                  }
            }
            
            else if( isalnum(s[i]) )
            {
                  if( !  (s[i+1] == ')' || isoperator(s[i+1]) ) )
                  {
                        cout<<"Invalid !!!\n\n";
                        return 0;
                  }
            
            }
            
            else if( isoperator(s[i]) )
            {
                  if (! (s[i+1] == '(' || isalnum(s[i+1]) ))
                  {
                        cout<<"Invalid !!!\n\n";
                        return 0;
                  }
            }
            
            else if( s[i]==')')
            {
                  if( !isoperator(s[i+1]) )
                        return 0;
            } 
      }                 

      return 1;

}

int main()
{
      string s;
      cin>>s;
      
     int check= read(s);
     
     while(check==0)
     {
            cin>>s;
            
            check=read(s);
      }
      
      cout<<s<<endl;
      
      return 0;
}            
      
      
      
