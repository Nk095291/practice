#include<bits/stdc++.h>
using namespace std;



int func(vector<int> &v)
{
	unordered_set<int> mp;
	int maxi = 0;
	for(int i = 0; i < v.size(); i++)
	{
		int x = v[i];
		if(x&1)
		{
			if(mp.count(x)==0)
				mp.insert(x);
			else 
				return 0;
			if(mp.count(2*x)==0)
				mp.insert(2*x);
			else
			 return 0;
		}
		else
		{
			while(x%2==0)
			{
				if(mp.count(x)==0)
					mp.insert(x);
				else 
					return 0;
				x = x/2;
			}
			if(mp.count(x)==0)
				mp.insert(x);
			else 
				return 0;
		}
	}
	vector<int> res;
	for(auto i : mp)
	{
		res.push_back(i);
	}
	sort(res.begin(),res.end());
	int mini = res.back()-res[0];
	for(int i = 0; i < res.size()-1; i++)
	{
		mini = min(mini,res[i+1]-res[i]);
	}

	return mini;
}
int main(){
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        vector<int> ar(n);
        for(int i =0;i<n;i++)
            cin>>ar[i];
        cout<<func(ar);
        cout<<endl;

    }
}