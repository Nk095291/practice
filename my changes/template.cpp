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
int sum=0;
    unordered_map<int,bool>visited;
void getsum(int i ,vector<unordered_set<int>>& mp){
    if(i>=mp.size()||mp[i].size()==0)
        return ;
    
    for(auto x:mp[i])
    {
        if(visited[x]==false)
        {
            visited[x]=true;
            getsum(i+1,mp);
            sum=(sum%minn+1%minn)%minn;
            visited[x]=false;
        }
    }

}

int main(){
    fast;
    int n;
    cin>>n;
    vector<int>res(n);
    f(n)
    {
 cin>>res[i];
 visited[res[i]]=false;
    }
       
    vector<unordered_set<int>>mp(n+1);
    for(auto x:res)
    {
        for(int i=1;i<=n;i++)
        {
            if(x%i==0)
            {
                mp[i].insert(x);
            }
        }
    }

    getsum(1,mp);
    cout<<sum<<endl;
}