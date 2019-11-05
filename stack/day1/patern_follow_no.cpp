#include<bits/stdc++.h>
using namespace std;
string min_no_that_follow_this_pat(string str)
{
    string res;
    string temp ;
    int c = 0;
    for(char s:str)
    {
        temp.push_back('0'+(++c));
        if(s=='i')
        {
            reverse(temp.begin(),temp.end());
            res+=temp;
            temp.clear();
        }
    }
    reverse(temp.begin(),temp.end());
    res+=temp;
    return res;
}
int main(){
    string pat = "ddddd";
    cout<<min_no_that_follow_this_pat(pat)<<endl;
}