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
    class helper{
        public:
        TreeNode* root;
        int status;
        helper(TreeNode* root,int status)
        {
            this->root = root;
            this->status = status;
        }
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        list<helper*>st;
        if(root)
        st.push_front(new helper(root,0));
        vector<int>res;
        while(st.size())
        {
            helper* rem = st.front();
            // cout<<(rem->root->val)<<" "<<rem->status<<endl;
            if((rem->status)==0)
            {
                rem->status++;
                if(rem->root->left)
                    st.push_front(new helper(rem->root->left,0));
                
            }else if(rem->status ==1)
            {
                res.push_back(rem->root->val);
                rem->status++;
                if(rem->root->right)
                {
                    st.push_front(new helper(rem->root->right,0));
                }
            }
            else {
                st.pop_front();
            }
      
        }
        return res;
    }
};