#include<bits/stdc++.h>
using namespace std;

bool isdup(string str)
{
   stack<char> st;
   for(char x:str)
   {
       if(x==' ')
        continue;           //for spaces
       if(x==')')
       {
           if(st.top()=='(')
            return true;
           while(st.top()!='(')
            st.pop();
            st.pop();
       }
       else
       {
           st.push(x);
       }
   }
   return false;
}
int main()
{
    cout<<isdup("(a + ( b+c +( ( d + e ) )  ) )")<<endl;
}