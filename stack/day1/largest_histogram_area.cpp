#include<bits/stdc++.h>
using namespace std;

void findNextSmaller(vector<int>&left,vector<int>&right,vector<int>&ar)
{

    stack<int> st;
    for(int i =0;i<ar.size();i++)
    {
        while(st.size()>0&&ar[i]<ar[st.top()])
        {
            int j = st.top();
            st.pop();
            right[j]=i;
            left[j]=st.size()==0?-1:st.top();
        }
        st.push(i);
    }
    while(st.size())
    {
        int i = st.top();st.pop();
        left[i]=st.size()==0?-1:st.top();
    }
}

int lha(vector<int>& ar)
{
    vector<int> left(ar.size());
    vector<int> right(ar.size(),ar.size());
    findNextSmaller(left,right,ar);

    int area =0;
    for(int i =0;i<ar.size();i++)
    {
        int cur_area = right[i]-left[i]-1;
        cur_area *=ar[i];
        area=max(cur_area,area);
    }
    return area;
}

int main(){
    vector<int> ar{6,2,5,4,5,1,6};
    cout<<lha(ar)<<endl;
}