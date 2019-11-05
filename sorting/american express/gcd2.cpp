#include <bits/stdc++.h>
using namespace std;
#define li 5000000
#define ll long long
vector<ll> vis(li);
bool primes[li];
ll pre[li + 1];
void sieve()
{
    for (int i = 0; i < li; i++)
    {
        vis[i] = i;
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (ll i = 2; i * i < li; i++)
    {
        if (vis[i] >= i)
        {
            for (ll j = i * i; j < li; j += i)
            {
                vis[j] = min(vis[j], i);
                primes[j] = false;
            }
        }
    }

    for (ll i = 2; i * i < li; i++)
    {
        ll n = i * i;
        unordered_map<ll, ll> map;
        while (n > 1)
        {
            map[vis[n]]++;
            n /= vis[n];
        }
        ll fac = 1;
        for (auto x : map)
        {
            fac *= (x.second + 1);
        }
        if(i==2)
        {
        cout<<fac<<endl;
        cout<<primes[fac]<<endl;
        cout<<primes[n]<<endl;
        }
        primes[n]=primes[fac];
        if(i==2)
        {
        cout<<primes[n]<<endl;            
        }
    }
    pre[0] = pre[1] = 0;

    for (int i = 2; i < li; i++)
    {
        pre[i] += pre[i - 1] + primes[i];
    }
}
int main()
{
    sieve();
    for(int i =0;i<10;i++)
        cout<<primes[i]<<" \n"[i==9];
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        int res = pre[r] - pre[l - 1];
        cout << res << endl;
    }
}

// for(ll i =1;i*i<li;i++)
// {
//     ll ans = 1;
//     ll n = i*i;
//     ll dup = vis[n];
//     ll c = 1;
//     ll j = n/vis[n];
//     while(j>1)
//     {
//         if(vis[j]==dup)
//         c++;
//         else
//         {
//             dup = vis[j];
//             ans=ans*(c+1);
//             c=1;
//         }
//         j/=vis[j];
//     }

//     ans = ans*(c+1);

//         primes[n]=vis[ans]==ans;
//     // pre[i]+=pre[i-1];
//     // if(primes[ans])
//     //     pre[i]++;
// }