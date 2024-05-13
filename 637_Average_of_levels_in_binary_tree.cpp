class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        long long sum=0;
        int noOfNodes=0;
        while(q.size()>1)
        {
            TreeNode* top=q.front();
            q.pop();
            if(!top)
            {
                q.push(NULL);
                ans.push_back(sum/double(noOfNodes));
                sum=0, noOfNodes=0;
                continue;
            }
            sum+=top->val;
            noOfNodes++;
            if(top->left)   q.push(top->left);
            if(top->right)  q.push(top->right);
        }
        ans.push_back(sum/double(noOfNodes));
        return ans;
    }
};