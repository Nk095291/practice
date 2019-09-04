/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
        class help {
        public:
        int min ;
        string s;
        help()
        {
            this->min=INT_MAX;
            this->s="";
        }
            help(int min , string s)
            {
                this->min = min;
                this->s=s;
            }
    };
    help* check(TreeNode* root )
    {
        if(root==NULL)
            return new help();
        help* left =check(root->left);
        help* right = check(root->right);
        help* res = NULL;
        if(left->min == right ->min )
        {
            if(left->s.size()>rigth->s.size())
            {
                
            }
            else{
                
            }
        }
        else if(left->min < right->min)
        {
            
        }else{
            
        }
         
            (res->min)= (root->val)<(res->min)?root->val : res->min;
            res->s += (char)(root->val + 'a');   
            return res;
        
        
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL)
            return "";
        help* res =check(root);
        return res->s;
    }
};