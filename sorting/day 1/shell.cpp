#include<bits/stdc++.h>
using namespace std;
void shell(int ar[],int n)
{
    for( int gap = n/2;gap>0;gap/=2)
    {
        for(int j=gap;j<n;j++)
        {
            for(int i=j-gap;i>=0;i-=gap)
            {
                if(ar[i]>ar[i+gap])
                    swap(ar[i],ar[i+gap]);
                else 
                    break;
            }
        }
    }
}
int main(){
    int ar[] = {23,29,15,19,31,7,9,5,2};
    int n = sizeof(ar)/sizeof(int);
    shell(ar,n);
    for(auto x:ar)
        cout<<x<<" ";
        cout<<endl;
}