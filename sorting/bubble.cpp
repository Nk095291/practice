#inlcude<bits/stdc++.h>
using namespace std;
void bubblesort(pair<int,int> ar[], int n)
{
    for(int i=0 ;i<n-1 ;i++)
    {
        for(int j=0 ; j<n-i-1; j++)
        {   
            if(ar[j]>ar[j+1])
                swap(ar[j],ar[j+1]);
        }
    }
}
int main(){
	
}