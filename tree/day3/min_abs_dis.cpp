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
        helper(){
            
        }
        helper(TreeNode* r, int s){
            root=r;
            status=s;
        }
    };
public:
    int getMinimumDifference(TreeNode* root) {
        list<helper*>st;
        st.push_front(new helper(root,0));
        int pre ;
        bool flag = false;
        int res=INT_MAX;
        while(st.size())
        {
            helper* rem = st.front();
            if(rem->status==0)
            {
             rem->status++;
                if(rem->root->left)
                    st.push_front(new helper(rem->root->left,0));
                
            }
            else if(rem->status==1)
            {
                if(!flag)
                {
                    flag=true;
                    pre = rem->root->val;
                    // cout<<pre<<endl;
                }
                else {
                    res= min(abs(rem->root->val - pre),res);
                    pre = rem->root->val;
                }
             rem->status++;
                if(rem->root->right)
                    st.push_front(new helper(rem->root->right,0));
                
            }
            else{
                st.pop_front();
            }
        }
        return res;
    }
};