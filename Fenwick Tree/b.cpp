#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&left,vector<int>&right,vector<int>&ar,int& count)
{
	int  i=0;
	int j =0;
	int k=0;
	while(i<left.size()&&j<right.size())
	{
		if(left[i]<=right[j])
			ar[k++]=left[i++];
		else
		{
			ar[k++]=right[j++];
			count+=(int)left.size()-i;
		}
	}
	while(i<left.size())
		ar[k++]=left[i++];
	while(j<right.size())
		ar[k++]=right[j++];
}

vector<int> mergesort(vector<int>&ar,int i ,int j,int & count)
{
	if(i==j)
	{
	vector<int>base{ar[i]};
	return base;
	}
	int mid = (i+j)/2;
	vector<int>left(mid+1);
	vector<int>right(j-mid);
	for(int a=i;a<=mid;a++)
	{
		left[a-i]=ar[a];
	}
	for(int a=mid+1;a<=j;a++)
	{
		right[a-mid-1]=ar[a];
	}
	left =mergesort(left,0,left.size()-1,count);
	right =mergesort(right,0,right.size()-1,count);
	vector<int>res(ar.size());
	 merge(left,right,res,count);
	 return res;
	
}
int main() {
	int t;
	cin>>t;

	int x;
	while(t--)
	{
		// cin>>x;
		int n;
		cin>>n;
		vector<int>ar(n);
		for(int i = 0 ;i < n ;i++)
		{
			cin>>ar[i];
		}

		int count=0;
		ar =mergesort(ar,0,n-1,count);
		for(auto x:ar)
		cout<<x<<" ";
		cout<<endl;
		cout<<"-------------\n";
		cout<<count<<endl;
	}
	return 0;
}