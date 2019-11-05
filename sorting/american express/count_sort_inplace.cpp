#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar={2,3,4,0,8,1,9,4,0,1,5,6,5,3,9,8,2,5,7,6,4,9,8,2,3,6,7,4,8,1};
    int mp[10]={0};
    for(auto x:ar)
        mp[x]++;
    int t=0;
    for(auto &x:mp)
        {
            int temp  = x;
            x=t;
            t+=temp;
            cout<<x<<" ";
        }
    cout<<endl;
    vector<int> res(ar.size());
    for(auto x:ar)
    {
       
        res[mp[x]]=x;
        mp[x]++;
    }
    for(auto x:res)
    cout<<x<<" ";
    cout<<endl;

/*
    if range is given from 100 to 110 then we still need mp of only 10 size .... we will just minus the lower range from every element
*/


}