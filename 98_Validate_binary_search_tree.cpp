class Solution {
public:
    bool isValid(TreeNode* root,long int min,long int max)
    {
        if(root==NULL)  return true;
        return (root->val<max) && (root->val>min) && isValid(root->left,min,root->val) && isValid(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};