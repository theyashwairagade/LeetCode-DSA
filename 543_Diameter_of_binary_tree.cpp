class Solution {
public:
    int diamater;
    int maxLength(TreeNode *root)
    {
        if(!root)  return 0;
        int rl=maxLength(root->left),ll=maxLength(root->right);
        diamater=max(diamater,rl+ll);
        return 1+max(rl,ll);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diamater=0;
        diamater=max(diamater,maxLength(root->left)+maxLength(root->right));
        return diamater;
    }
};