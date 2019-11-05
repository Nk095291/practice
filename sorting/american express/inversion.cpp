#include<bits/stdc++.h>
using namespace std;
int count =0;


void margetwo(vector<int>& ar,int l,int mid,int r){
    int i =1;
    int j = mid+1;
    int 
    while(i<=l&&j<=r)
    {
        if(ar[i]<ar[j])
        {
            
        }
        else{

        }
    }
    while (i<=l)
    {
        
    }
    while(j<=r)
    {

    }
    
}

void mergesort(vector<int>&ar , int low,int high)
{
    if(low>=high)
    return ;
    int mid = (high+low)/2;
    mergesort(ar,low,mid);
    mergesort(ar,mid+1,high);
    mergetwo(ar,low,mid,high);
}
int main()
{
    vector<int>ar={2 5 1 8 6 3 7 6};
    mergesort(ar,0,ar.size()-1);
    cout<<count<<endl;
}