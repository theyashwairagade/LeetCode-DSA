// Brutte force
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


// More Optimized
class Solution {
public:
    int calculateLeftDepth(TreeNode* root)
    {
        int ans=0;
        while(root)
            root=root->left,ans++;
        return ans;
    }
    int rightDepth(TreeNode* root)
    {
        int ans=0;
        while(root)
            root=root->right, ans++;
        return ans;
    }
    int countNodes(TreeNode* root) {
        int leftDepth=calculateLeftDepth(root);
        if(leftDepth==rightDepth(root))
            return pow(2,leftDepth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};