#include<bits/stdc++.h>
using namespace std;
void dr(vector<int>& ar)
{
    sort(ar.begin(),ar.end());
    for(int i=ar.size()-1;i>0;i--)
    {
        if(ar[i]==ar[i-1])
            ar.erase(ar.begin()+i);
    }
}
int solve(vector<vector<int>>& ar,int count)
{
    int flag =true;
    unordered_map<int,int>mp;
    for(int i=0;i<ar.size();i++)
    {
        for(int j=0;j<ar[0].size();j++)
        {

            mp[ar[i][j]]++;
            if(mp[ar[i][j]]>2)
            {
                flag = false;
            }
        }
    }
    if(flag)
    return count;

    int res=INT_MAX;

    for(int i =0;i<ar.size();i++)
    {
        for(int j=i+1;j<ar.size();j++)
        {
            vector<int> a (ar[i]);
            vector<int> b (ar[j]);

            vector<int> temp (ar[i]);
            temp.insert(temp.end(),ar[j].begin(),ar[j].end());
            
            dr(temp);

            ar.erase(ar.begin()+i);
            ar.erase(ar.begin()+j);
            ar.push_back(temp);

          res= min(res,solve(ar,count+1)) ;
            ar.pop_back();
            ar.insert(ar.begin()+i,a);
            ar.insert(ar.begin()+j,b);
        }
    }
 return res;

}

int main()
{
    int n,m;
    cin>> n>>m;
    vector<vector<int>>com(n,vector<int>(m));
    for(int i =0;i<n;i++)
    {
       
        for(int j=0;j<m;j++)
        {
           cin>>com[i][j];

        }
        dr(com[i]);
        
    }
    cout<< solve(com,0)<<endl;
}