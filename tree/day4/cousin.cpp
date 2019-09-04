class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        list<TreeNode*> st;
        st.push_back(root);
        while(st.size())
        {
            int len = st.size();
            bool one=false,two=false;
            for(int i=0;i<len;i++)
            {
                TreeNode* rem = st.front();st.pop_front();
                if(rem->val==x)
                    one=true;
                else if(rem->val == y )
                    two = true;
                if(rem->left && rem->right)
                {
                    int l = rem->left->val;
                    int r = rem->right->val;
                    if((l==x&&r==y)||(l==y&&r==x))
                        return false;
                }
                if(rem->left)
                {
                    st.push_back(rem->left);
                }
                if(rem->right)
                {
                    st.push_back(rem->right);
                }
                
            }
            if(one&&two)
                return true;
            else if(one||two)
                return false;
        }
        return false;
    }
};