#include<bits/stdc++.h>
using namespace std;
void update(int x,int delta,vector<int>&ar)
{
    x++;
    for(int i=x;i<ar.size();i+=-i&i)
    {
        ar[i]+=delta;
    }
}
int sum(int x,vector<int>&ar)
{
    x++;
    int ans =0;
    for(int i =x;i>0;i-=i&-i)
    {
        ans +=ar[i];
    }
    return ans;
}
int main(){
    vector<int>ar{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<int>fenwick(ar.size()+1);
    for(int i=0;i<ar.size();i++){
        update(i,ar[i],fenwick);
    }
    cout<<sum(7,fenwick)-sum(6,fenwick)<<endl;

}