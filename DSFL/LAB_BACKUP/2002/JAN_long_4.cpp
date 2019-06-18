#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
      int t;
      cin>>t;
      
      while(t--)
      {
            int n,x;
            cin>>x>>n;
            
            int ans[n+1]={0};            
            
            ans[x]=2;
            
            ll sum=(n*(n+1))/2;
            
            ll c1=0;
            
            ll rem=sum-x;
            
            if(rem %2 != 0)            
                  cout<<"Impossible\n";
            
            else
            {
                  rem /= 2;
                  //cout<<rem<<endl;
                  int i=n;
                  
                  while(rem > 0)
                  {
                        if(i==x)
                        {
                              i--;
                              continue;
                        }
                        
                        else if(ans[i]==1)
                        {
                              i--;
                              continue;
                        }
                        
                        if( ( (rem-i)<i ) && ( (rem-i)!=x ) )
                        {
                              ans[rem-i]=1;
                              ans[i]=1;
                              rem=0;
                        }
                        
                        if( (rem-i)>=i ) 
                        {
                              ans[i]=1;
                              rem -= i;
                        }
                        
                        i--;
                  }
                  
                  for(int j=1;j<n+1;j++)
                  {
                        if(i==x)
                              continue;
                        
                        if(ans[i]==0)
                              break;
                  }
                  
                  if(i==n+1)                  
                        cout<<"impossible\n";
                  
                  else
                  {
                        for(int j=1;j<n+1;j++)
                              cout<<""<<ans[j];
                        
                        cout<<endl;
                  }
            
            }
                  
      }
      
      return 0;
}      
