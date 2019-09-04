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
public:
    vector<vector<int>>res;
    void solve(TreeNode* root, int sum , vector<int>& temp)
    {
        if(!root)return ;
        temp.push_back(root->val);
        if(!root->left&&!root->right&&(sum==root->val))
            res.push_back(temp);
        solve(root->left,sum-root->val,temp);
        solve(root->right,sum-root->val,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>temp;
        solve(root,sum,temp);
        return res;
    }
};