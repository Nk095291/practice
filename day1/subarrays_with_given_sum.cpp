#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double fd;
int minn=1e9;
#define f(n) for(int i=0;i<n;i++)
#define f1(a,n) for(int i=a;i<n;i++)
#define f2(j,n) for(int j=0;j<n;j++)
#define f3(j,a,n) for(int j=a;j<n;j++)
#define fast 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        vector<int>res(n);
         int t=0;
        f(n)
        {
            cin>>res[i];
            t+=res[i];
            res[i]=t;
        }

        int target;
        cin>>target;
        unordered_map<int,int>mp;
        mp[res[0]]++;
        int c = target==res[0]?1:0;
        f1(1,n)
        {
            c=res[i]==target?c+1:c;
            if(mp.count(res[i]-target))
            {
  
                c+=mp[res[i]-target];
          
            }
            mp[res[i]]++;
        }
        
        cout<<c<<endl;
    }
}