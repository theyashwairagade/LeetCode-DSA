int valueAt(TreeNode* root, int prefix)
{
    prefix+=root->val;
    if(!root->left && !root->right)     return prefix;

    int ans=0;
    if(root->left)  ans+=valueAt(root->left,prefix*10);
    if(root->right) ans+=valueAt(root->right,prefix*10);
    return ans;
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        return valueAt(root,0);
    }
};