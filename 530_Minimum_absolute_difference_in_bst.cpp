class Solution {
public:
    void findInorder(TreeNode* root, vector<int> &inorder)
    {
        if(!root)   return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        int n=inorder.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
            ans=min(ans,inorder[i]-inorder[i-1]);
        return ans;
    }
};