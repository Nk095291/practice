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

void swap(int&a ,int &b)
{
    int temp =a;
    a=b;
    b= temp;
}

int main(){
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>> n;
        vector<int>res(n);
        f(n)
        cin>>res[i];
        int i =0;
        int j = res.size()-1;
        for(int k=0;k<n&&i<j;k++)
        {
            if(res[k]==0)
            {

                swap(res[i++],res[k]);
                	if(res[k]==2)
                	{
                		swap(res[j--],res[k]);
                	}
            }
            if(res[k]==2)
            {
            	while(j>=0&&res[j]==2)
            		j--;
            	if(j<k)
            		break;
            	swap(res[j--],res[k]);
            	if(res[k]==0)
            		swap(res[i++],res[k]);
            }
        }
        f(n)
        cout<<res[i]<<" ";
        cout<<endl;
    }
}