#include<bits/stdc++.h>
using namespace std;

bool opening(char x)
{
    return x=='('||x=='{'||x=='[';
}

bool closing(char x)
{
    return x==')'||x=='}'||x==']';
}

char counter(char x)
{
    char res;
    switch (x)
    {
    case ')':res='('; break;
    case ']':res='['; break;
    case '}':res='{'; break;
    default:
        break;
    }
    return res;
}
bool valid (string str)
{
    stack<char>st;
    for(char x:str)
    {
        if(closing(x))
        {
            if(st.size()==0 ||  st.top()!=counter(x))
                return false;
            st.pop();
        }
        else if(opening(x)){
            st.push(x);
        }
    
    }
    return st.size()==0;
}

int main()
{
    string s = "[a+{b+(d+e)}]";
    string a = "[a+{b+(d+e))]";
    string b = "[a+{b+(d+e)}";
    string c = "a+{b+(d+e)}]";
    cout<<valid(s)<<endl;
    cout<<valid(a)<<endl;
    cout<<valid(b)<<endl;
    cout<<valid(c)<<endl;

}