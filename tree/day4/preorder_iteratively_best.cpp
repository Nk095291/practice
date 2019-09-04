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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        list<TreeNode*> st;
        while(st.size()||root)
        {   
            if(root)
            {
                res.push_back(root->val);
                st.push_front(root);
                root=root->left;
            }else{
                TreeNode* rem = st.front();st.pop_front();
                root = rem ->right;
            }
        }
        return res;
        
    }
};