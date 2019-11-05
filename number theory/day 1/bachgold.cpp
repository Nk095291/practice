#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    if(n&1)
    {   
        n=n-3;
        cout<<(n/2)+1<<endl;
        cout<<3<<" ";
    }
    else
        cout<<n/2<<endl;
      while(n>1)
        {
            cout<<2<<" ";
            n-=2;
        }
        cout<<endl;
}