#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> mp;
    for(int i =0;i<50 ;i+=10)mp.insert(i);
    for(auto x:mp)
        cout<<x<<endl;
}