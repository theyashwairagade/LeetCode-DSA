class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* top=NULL;

        vector<int> ans;
        while(q.size()>1)
        {
            if(!top)   ans.push_back(q.front()->val);
            top=q.front();
            q.pop();
            if(!top)
                q.push(NULL),
                continue;

            if(top->right)  q.push(top->right);
            if(top->left)   q.push(top->left);
        }
        return ans;
    }
};