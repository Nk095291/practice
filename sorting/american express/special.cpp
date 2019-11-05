#include<bits/stdc++.h> 
using namespace std; 
#define int long long

int gcd(int a,int b)
{
    if(a==0)
    return b;
    return gcd(b%2,a);
}

int la , lac , lbc , labc ;
int getlcm(int a ,int b){
	return (a*b)/gcd(a,b) ;
}
int solve(int a , int b ,int c , int mid){
	int val = mid/a + mid/b + mid/c - mid/la - mid/lac - mid/lbc + mid/labc; 
	return val ;
}
int kthElement(int a, int b, int c , int n) 
{ 
    int l = 1, r = min({a,b,c})*n , mid , minans = 1e18;
    while (l <= r) 
    {   mid = (l+r)>>1 ;
       int  val = solve(a,b,c,mid) ;
        if (val == n){ 
                minans = min(mid, minans) ;
        } 
        if (val < n) 
            l = mid + 1; 
        else
            r = mid - 1; 
    }
    return minans ;
}  
int32_t main() 
{   int t ;
    cin >> t ;
    while(t--){
    int a , b , c , k ;
    cin >> a >> b >> c >> k ;  
	la = getlcm(a,b) , lbc = getlcm(b,c) , lac = getlcm(a,c) ; 
     labc = getlcm(a,getlcm(b,c)) ;
     cout << kthElement(a,b,c,k) << '\n' ;
    }
}