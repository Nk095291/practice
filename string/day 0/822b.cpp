#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a;
    cin>>b;
    int minn = n;
    int index = 0;
    for(int i=0;i+n<=m;i++)
    {
        int res =n;
        for(int j=0;j<n;j++)
        {
            if(a[j]==b[i+j])
                res--;
        }
        index = minn>res?i:index;
        minn = min(res,minn);
    }
    cout<<minn<<endl;
    for(int i=index;i<n+index;i++)
    {
        if(b[i]!=a[i-index])
            cout<<i-index+1<<" ";
    }
    cout<<endl;
 
}