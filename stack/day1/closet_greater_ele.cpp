#include<bits/stdc++.h>
using namespace std;

vector<int> gce(vector<int>& ar)
{
    stack<int> st;
    vector<int> res(ar.size());
    for(int i = ar.size()-1;i>=0;i--)
    {
        while(st.size()&& st.top()<ar[i])
        {
            st.pop();
        }
        if(st.size()==0)
            res[i]=-1;
        else
            res[i]=st.top();
        st.push(ar[i]);
    }
    return res;
}
vector<int>gce2(vector<int>& ar)
{
    stack<int> st;
    vector<int> res (ar.size(),-1);
    for(int i =0;i<ar.size();i++)
    {
        while(st.size()&&ar[i]>ar[st.top()])
        {
            res[st.top()]=ar[i];
            st.pop();
        }
        st.push(i);
    }
    return res;

}
int main(){
    vector<int> ar {5,9,8,3,2,7,16,14,4,14,19,3};
    vector<int> res = gce2(ar);
    for(int x:res)  
        cout<<x<<" ";
    cout<<endl;

}