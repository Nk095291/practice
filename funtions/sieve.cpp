#include<bits/stdc++.h>
using namespace std;

vector<int> letspf(int n )
{
    vector<int> res(n+1);
    for(int i=0;i<=n;i++)res[i]=i;
    vector<bool>prime(n+1);
    for(int i =2;i*i<=n;i++)
    {
        if(prime[i]==false)
        {
            res[i]=i;
            for(int j=i;i*j<=n;j++)
            {
                if(prime[i*j]==false)
                {
                    prime[i*j]=true;
                    res[i*j]=i;
                }
            }
        }
    }
    return res;

}

void fact(vector<int>&res ,int x)
{
    cout<<x<<" =  ";
    while(x>1)
    {
        cout<<res[x]<<" * ";
        x/=res[x];
    }
    cout<<endl;
}
int main(){
    vector<int> res = letspf(100000);
    fact(res,144);

}