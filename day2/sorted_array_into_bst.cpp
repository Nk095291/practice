class Solution {
public:
    
    TreeNode* makeTree(vector<int>&nums,int i, int j )
    {
        if(i>j)
            return NULL;
    
        int mid = (i+j)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTree(nums,i,mid-1);
        root->right = makeTree(nums,mid+1,j);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        return makeTree(nums,0,nums.size()-1);
        
    }
};