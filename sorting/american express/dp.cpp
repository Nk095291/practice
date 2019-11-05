#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int arr[N];
vector<int> odd;
vector<int> even;
int DP[N][26];
int n, k;
const int mod = 1e9 + 7;

int f(int idx, int prev)
{
    if(idx == n) return 1;
    int cnt = 0;
    if(DP[idx][prev] != -1) return DP[idx][prev];
    if((idx + 1) & 1)
    {
        for(int x : odd)
        {
            if(prev == x) continue;
            cnt += f(idx + 1, x);
            cnt %= mod;
        }
    }
    else
    {
        for(int x : even)
        {
            if(prev == x) continue;
            cnt += f(idx + 1, x);
            cnt %= mod;
        }
    }
    return DP[idx][prev] = cnt;
}


void solve()
{
    cin >> n >> k;
    odd.clear();
    even.clear();
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            DP[i][j] = -1;
        }
    }
    for(int i = 0; i < k; i++)
    {
        char data;
        cin >> data;
        odd.push_back(data - 'a');
    }
    for(int i = 0; i < 26; i++) 
    {
        even.push_back(i);
    }
    int ret = 0;
    for(int x : odd)
    {
        ret += f(1, x);
        ret %= mod;
    }
    cout << ret << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--) solve();
}