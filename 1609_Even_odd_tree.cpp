class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // TreeNode* zero= new TreeNode(0);
        int remainder=1;
        int previous=INT_MIN;

        queue<TreeNode*> q;
        q.push(root);
        q.push(new TreeNode(0));
        while(q.size()>1)
        {
            TreeNode* top=q.front();
            if(top==NULL)   q.pop();
            else if(top->val==0)
            {
                if(remainder)
                {
                    remainder=0;
                    previous=INT_MAX;
                }   
                else
                {
                    remainder=1;
                    previous=INT_MIN;
                }    
                q.push(new TreeNode(0));
                q.pop();
            }else
            {
                if(top->val%2!=remainder)   return false;
                if(remainder)
                {
                    if(top->val<=previous)  return false;
                }
                else    if(top->val>=previous)  return false;
                previous=top->val;
                q.push(top->left);
                q.push(top->right);
                q.pop();
            }
        }
        return true;
    }
};