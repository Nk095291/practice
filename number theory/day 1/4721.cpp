#include<bits/stdc++.h>
using namespace std;
#define MAX 1e6
vector<int> prime(MAX,true);
void sieve()
{

    for(int i =2;i*i<MAX;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<MAX;j+=i)
                prime[j]=false;
        }
    }
}

int main()
{
    sieve();
    int n ;
    cin>>n;
     int a ,b;
    if(n&1)
    {
        a = n/2;
        b=a+1;
    }
    else{
       
        a=b=n/2;
        a--;
        b++;
      
    }
      while(prime[a]||prime[b])
        {
            a--;
            b++;
        }
        cout<<a<<" "<<b<<endl;
}