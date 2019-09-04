#include<bits/stdc++.h>
using namespace std;

long long com(int n,int r)
{
 long long p =1,k=1;
 if(n-r<r)
 r=n-r;
 if(r)
 {
     while(r)
     {
         p*=n;
         k*=r;
         long long m = __gcd(p,k);
         p/=m;
         k/=m;
         n--;
         r--;
     }
 }else
 {
     p=1;
 }
 return p;
}

int main(){
    cout<<com(5,3)<<endl;
}