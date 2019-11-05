#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp
{
    {'+',1},
    {'-',1},
    {'*',2},
    {'/',2},
    {'%',2},
    {'^',3},
};

int getresult(int a,int b,int ch)
{
    if(ch=='+')
        return a+b;
    if(ch=='-')
        return a-b;
    if(ch=='*')
        return a*b;
    if(ch=='/')
        return a/b;
    if(ch=='%')
        return a%b;
    return pow(a,b);  
}
int solve(string exp)
{
    stack<int>operand;
    stack<char>operation;
    stack<string>pre;
    stack<string>post;
    operation.push('(');
    exp+=')';
    for(char x:exp)
    {
        if(x>='0'&&x<='9')
        {
            operand.push(x-'0');
        }
        else if(x=='(')
        {
            operation.push(x);
        }
        else if(x==')')
        {
                while(operation.top()!='(')
                {
                    int val2 = operand.top();operand.pop();
                    int val1 = operand.top();operand.pop();
                    int res = getresult(val1,val2,operation.top());
                    operand.push(res);
                    operation.pop();
                }
                    operation.pop();
        }
        else
        {
                while(operation.size()&&operation.top()!='('&&mp[operation.top()]>=mp[x])
                {
                    int val2 = operand.top();operand.pop();
                    int val1 = operand.top();operand.pop();
                    int res = getresult(val1,val2,operation.top());
                    operand.push(res);
                    operation.pop();
                }
                operation.push(x);
        }
    }
    return operand.top();
}

int main(){
    string exp = "8+3^(1/(3-2))";
    cout<<solve(exp)<<endl;
}