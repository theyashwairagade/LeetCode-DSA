class Solution {
    int solve (TreeNode* root, int val){
        if(!root)
            return 0;
        int right = solve(root->right, val);
        if(!right)
            root->val += val;
        else
            root->val += right;
        int left = solve (root->left, root->val);
        if(left)
            return left;
        return root->val;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve (root, 0);
        return root;
    }
};