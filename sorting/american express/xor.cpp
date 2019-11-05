#include<bits/stdc++.h>
using namespace std;
#define int long long 

void display(vector<int>& res)
{
  sort(res.begin(),res.end());
      for(int i =0;i<res.size();i++)
        cout<<res[i]<<" \n"[i==res.size()-1];
}
void solve(int n ,int x)
{
    vector<int>res;
    for(int i=0;i<64;i++)
    {
        if(x&((int)1<<i))
        {
            res.push_back(((int)1<<i));
        }
    }
  if(res.size()>n)
  {
      int i=0,j=res.size()-1;
      while(j-i+1>n)
      {
          res[n-1]+=res[j];
          j--;     
      }
      res.erase(res.begin()+j+1,res.end());
      display(res);
    return ;    
  }
  int diff=n-res.size();
  
  for(int i=0;i<diff;i++)
    res.push_back(1);
  sort(res.begin(),res.end());
  if(diff&1)
  {  if(x!=1)
    {
        int i=res.size()-1;
        while(res[i]>1 && i>=0)
           i--;
        res[i+1]++;
    }
     else
     {
         res[n-1]+=2;
         res[n-2]+=1;
     }
  }
display(res);
}
int32_t main()
{
  int n,x;
  cin>>n>>x;
  solve(n,x);
}