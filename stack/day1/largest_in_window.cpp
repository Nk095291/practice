#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int>& ar)
{
    stack<int>st;
    vector<int>res(ar.size());
    for(int i =ar.size()-1;i>=0;i--)
    {
        while(st.size() && ar[i]>ar[st.top()])
        {
            st.pop();
        }
        res[i]=st.size()==0?ar.size():st.top();
        st.push(i);
    }
    return res;
}

void window(vector<int>& ar)
{
    vector<int> right = nge(ar);
    for(auto x:right)
        cout<<x<<" ";
    cout<<endl;
    int i =0;
    int j =0;
    while ((i<ar.size()-5+1))
    {
        if(i>j)
            j=i;
        while(right[j]<i+5)
            j = right[j];
        cout<<ar[j]<<" ";
        i++;
    }
    cout<<endl;
    
}

int main(){
    vector<int>ar {5,9,3,1,8,6,7,2,11,4,17};
    window(ar);
}