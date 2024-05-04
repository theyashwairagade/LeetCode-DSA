class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        vector<int> temp;
        while(q.size()>1)
        {
            TreeNode* top=q.front();
            q.pop();
            if(!top)
            {
                q.push(NULL);
                ans.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(top->val);
            if(top->left)   q.push(top->left);
            if(top->right)  q.push(top->right);
        }
        ans.push_back(temp);
        return ans;
    }
};