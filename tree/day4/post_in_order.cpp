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
       unordered_map<int,int>mp;
   TreeNode* construct(vector<int>& in , int ii, int ie, vector<int>& post, int pi,int pe)
    {
        if(ii<=ie&&pi<=pe)
        {
            int data =post[pe];
            TreeNode* root = new TreeNode(data);
            int left = mp[data]-ii;
            root->left = construct(in,ii,mp[data]-1,post,pi,pi+left-1);
            root->right = construct(in,mp[data]+1,ie,post,pi+left,pe-1);
            return root;
            
        }
        else return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     
        for(int i =0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return construct(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};