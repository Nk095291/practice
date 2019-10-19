#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double fd;
int minn=1e9;
#define f(n) for(int i=0;i<n;i++)
#define f1(a,n) for(int i=a;i<n;i++)
#define f2(j,n) for(int j=0;j<n;j++)
#define f3(j,a,n) for(int j=a;j<n;j++)
#define fast 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int octalToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
  
        base = base * 8; 
    } 
  
    return dec_value; 
}

int main(){
    fast;
    int oct,thre;
    string bin;
    cin>>oct>>bin>>thre;
    oct = octalToDecimal(oct);
    thre=  octalToDecimal(thre);
    bitset<32>t(bin);
    int b = t.to_ullong();
    if(abs(oct-b)>=thre)
        cout<<"john";
    else 
        cout<<"Ceena";
}