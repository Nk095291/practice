#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double fd;
int mod=1e9+7;
#define f(n) for(int i=0;i<n;i++)
#define f1(a,n) for(int i=a;i<n;i++)
#define f2(j,n) for(int j=0;j<n;j++)
#define f3(j,a,n) for(int j=a;j<n;j++)
#define fast 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int _gcd(int a, int b)
{
    if(a==0) return b;
    return _gcd(b%a,a);

}
int otd(int n) 
{ 
    int dec_value = 0; 
    int base = 1; 
    int temp = n; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 8; 
    } 
    return dec_value; 
} 
int phi(int n) 
{ 
    double result = n; // Initialize result as n 
    for (int p = 2; p * p <= n; ++p) { 
        
        // Check if p is a prime factor. 
        if (n % p == 0) { 
            
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (double)p)); 
        } 
    } 
    if (n > 1) 
        result *= (1.0 - (1.0 / (double)n)); 

    return (int)result; 
} 





int power(int a, int n)
{
    if(n==0) return 1;
    if(n==1) return a;
    int x = power(a,n/2);
    x  = (x*x)%mod;
    if(n&1) x=(x*a)%mod;
    return x;
}
int fermat(int a )
{
        return power(a,mod-2);  
}
int modexp(int a , int n){
    if(n == 0) return 1 ;
    if(n == 1) return a ;
    int x = modexp(a,n/2) ;
    x = (x*x)%mod ;
    if(n&1) x = (x*a)%mod ;
    return x ;
}

int32_t main(){
    int n;
    cin>>n;
    int q = n - phi(n);
    int p=n;

     cout << (q*power(p,mod-2))%mod ;
}