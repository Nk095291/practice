#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    bool eow;
    unordered_map<char,Node*>children;
    Node(char data,bool eow)
    {
        this->data = data;
        this->eow=eow;
    }
};

void push(string word, int idx ,Node* root)
{
    if(idx == word.size())
    {
        root->eow = true;
        return;
    }
    char ch = word[idx];
    if(root->children.count(ch)==0)
    {
        root->children[ch]= new Node(ch,0);
    }
    Node* next_root = root->children[ch];
    push(word,idx+1,next_root);
}

bool search(string word,int idx , Node* root)
{
    if(idx==word.size())
    {
        return root->eow;
    }
    char ch = word[idx];
    if(! root->children.count(ch))
    {
        return false;
    }
    return search(word,idx+1,root->children[ch]);

}

int main(){
    Node* root = new Node('$',0);
    push("hi",0,root);
    push("as",0,root);
    push("ask",0,root);
    push("see",0,root);
    push("seen",0,root);
    cout<<search("see",0,root)<<endl;
    cout<<search("seen",0,root)<<endl;
    cout<<search("sea",0,root)<<endl;
    
}