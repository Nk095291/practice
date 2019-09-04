#include<bits/stdc++.h>
using namespace std;
int cat(int n )
{
    int res=1;
    for(int i = n+1;i<=n*2;i++)
    {
        res*=i/(i-n);
    }
    return res/n+1;
}
int main()
{
    cout<<cat(3);
}