#include<bits/stdc++.h>
using namespace std;
int solve(vector<bool>&visited, int k,vector<vector<int>>&person,int i)
{
    if(i==person.size())
    {
        return 1;
    }
    int sum =0;
    for(auto x: person[i])
    {
        if(visited[x]==false)
        {
            visited[x]=true;
            sum+=solve(visited,k,person,i+1);
            visited[x]=false;
        }
    }
    return sum;
}

int solve2(vector<vector<int>>&visited, int k,vector<vector<int>>&person,int i)
{
    if(i==person.size())
    {
        return 1;
    }
    bitset<5> bit(k);
    cout<<i<<" "<<bit<<endl;
    int sum =0;
    if(visited[i][k]!=-1)
        return visited[i][k];
    for(auto x: person[i])
    {
        if((k&(1<<x))==0)
         sum+=solve2(visited,(k|(1<<x)),person,i+1);
    }
    visited[i][k]=sum;
    return sum;
}



int main(){
    vector<vector<int>> person = {
        {0,2,4},
        {0,1,2,3},
        {1,2,3},
        {0,4},
    };
    vector<bool>visited(5);

    vector<vector<int>>res(5,vector<int>(1<<5,-1));

    cout<<solve2(res,0,person,0)<<endl;

}