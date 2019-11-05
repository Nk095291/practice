#include<bits/stdc++.h>
using namespace std;
int no_of_digit(int n )
{
    return log10(n)+1;
}

vector<int> cs(vector<int>&ar, int div)
{
    int mp[10]={0};
    for(auto x:ar)
        mp[(x/div)%10]++;
    int t=0;
    for(auto &x:mp)
        {
            int temp  = x;
            x=t;
            t+=temp;
        
        }
    vector<int> res(ar.size());
    for(auto x:ar)
    {
        res[mp[(x/div)%10]]=x;
        mp[(x/div)%10]++;
    }
    for(int x:res)
    cout<<x;
    cout<<endl;
    return res;
}
int main()
{
    vector<int> ar = {259,68,347,924,136,425,719,88,463,527,634,725,978};
    int m=INT_MIN;
    for(int x:ar)
        m = max({x,m});

    int div = 1;
    while( (m/div) >0)
    {
        ar = cs(ar,div);
        div*=10;
    }
    for(int x:ar)
    {
        cout<<x<<" ";
    }
    cout<<endl;

}