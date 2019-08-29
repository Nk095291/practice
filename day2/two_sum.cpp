    bool findTarget(TreeNode* root, int target) {
        list<helper*> left ;
        list<helper*> right;
        left.push_front(new helper(root,0));
        right.push_front(new helper(root,0));
        bool ml=true;
        bool mr=true;
        int leftval =0;
        int rightval =0;
        while(true)
        {   
                while(left.size()&&ml)
                {
                    helper* rem = left.front();
                    if(rem->status==0)
                    {
                        rem->status++;
                        if(rem->root->left)
                        left.push_front(new helper(rem->root->left,0));
                    }
                    else if(rem->status==1){
                        rem->status++;
                        leftval = rem->root->val;
                        ml=false;
                       
                        if(rem->root->right)
                            left.push_front(new helper(rem->root->right,0));
                         break;
                    }else{
                        left.pop_front();
                    }
                }  
             while(right.size()&&mr)
                {
                    helper* rem = right.front();
    
                    if(rem->status==0)
                    {
                        rem->status++;
                        if(rem->root->right)
                        right.push_front(new helper(rem->root->right,0));
                    }
                    else if(rem->status==1){
                        rem->status++;
                        rightval = rem->root->val;
                        mr=false;
                        if(rem->root->left)
                            right.push_front(new helper(rem->root->left,0));
                        break;
                    }else{
                        right.pop_front();
                    }
                }
            // cout<<leftval<<" "<<rightval<<endl;
            if(leftval>=rightval)
                break;
            int sum = leftval+ rightval;
            if(sum<target) // we have lesser value so move the left stack
            {
                ml=true;
            }else if(sum>target) // we have more the req. value so move the right stack
            {
                mr = true;
            }
            else {
                return true;
            }
            
        }
        return false;
    }