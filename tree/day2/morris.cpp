// reverse morris traversal

TreeNode* convertBST(TreeNode* root) {
    
        TreeNode* cur = root;
          int sum =0;
          while(cur)
          {
                if(!cur->right)
                {
                     sum+=cur->val;
                      cur->val = sum;
                    cur=cur->left;
                }
              else {
                  TreeNode* pre = cur->right;
                  while(pre->left&&pre->left!=cur)
                      pre=pre->left;
                  if(pre->left)
                  {
                      pre->left=NULL;
                      sum+=cur->val;
                      cur->val = sum;
                      cur=cur->left;
                  }else{
                      pre->left = cur;
                      cur=cur->right;
                  }
                      
              }
          }
          return root;
    }