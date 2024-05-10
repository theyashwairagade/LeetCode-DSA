class Solution {
public:
    int valid(int left, int right)
    {
        if(left==-1 || right==-1)
            return -1;
        if(abs(left-right)<2)
            return 1+max(left,right);
        return -1;
    }
    int height(TreeNode* root)
    {
        if(!root)   return 0;
        return valid(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};