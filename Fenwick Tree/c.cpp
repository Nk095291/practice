#include<bits/stdc++.h>
using namespace std;
void compress(vector<int>&ar )
{
    vector<pair<int,int>>res(ar.size());
    for(int i=0;i<res.size();i++)
        res[i]={ar[i],i};
    sort(res.begin(),res.end());
    for(int i=0;i<ar.size();i++)
    {
        ar[res[i].second]=i+1;
    }

}
void update(vector<int>&ar,int x,int delta)
{
    x++;
    for(int i=x;i<=ar.size();i+=i&-i)
    {
        ar[i]=delta;
    }
}
int sum (vector<int>&ar,int pos)
{
    int ans =0;
    for(int i=pos;i>0;i-=i&-i)
        ans+=ar[i];
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<ar.size();i++) cin>>ar[i];
        compress(ar);
        vector<int>fenwick(ar.size()+1);
        int ans=0;
        for(int i=ar.size()-1;i>=0;i--)
        {
            ans+=sum(fenwick,ar[i]);
            update(fenwick,ar[i],1);
        }
        cout<<ans;
    }
}