class Solution {
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->left&&!root->right)
            return sum==root->val;
        bool left = hasPathSum(root->left,sum-root->val);
        if(left)
            return left;
        bool right = hasPathSum( root->right,sum-root->val);
        return right;    
    }
};