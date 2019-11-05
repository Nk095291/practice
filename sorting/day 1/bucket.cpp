#include<bits/stdc++.h>
using namespace std;

// bucket sort is used when the number are float and  distributed uniformly in a range ... as they as floating  numbers so we can't apply 
// counting sort here.
void bucket(vector<float> &ar)
{
    vector<vector<float>> bucket(ar.size());
    for(auto x:ar)
    {
        int idx = x*ar.size();
        bucket[idx].push_back(x);
    }
    for(auto i =0;i<bucket.size();i++)
    {

        sort(bucket[i].begin(),bucket[i].end());
    }

        int k=0;
    for(int i =0;i<bucket.size();i++)
    {
        for(int j=0;j<bucket[i].size();j++)
        {
            ar[k++]=bucket[i][j];
        }
    }

}
int main(){
    vector<float> ar {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucket(ar);
    for(auto x:ar)
    cout<<x<<" ";
    cout<<endl;
}