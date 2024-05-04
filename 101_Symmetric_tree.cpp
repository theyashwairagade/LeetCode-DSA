class Solution {
public:
    bool isSymmetric(TreeNode *l, TreeNode *r)
    {
        if(l && r)
        {
            if(l->val != r->val)    return false;
            return (isSymmetric(l->left,r->right)&& isSymmetric(l->right,r->left));
        }
        if(l || r)  return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left,root->right);
    }
};