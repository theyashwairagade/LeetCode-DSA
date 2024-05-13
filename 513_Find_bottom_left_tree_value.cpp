class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty())
        {
            TreeNode * current=q.front();
            if(current!=NULL)
            {
                ans=current->val;
                q.push(current->right);
                q.push(current->left);
            }
            q.pop();
        }
        return ans;
    }
};