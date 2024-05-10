// Time complexity O(n) space complexity O(n)
class Solution {
public:
    void findInorder(TreeNode* root, vector<int> &inorder)
    {
        if(!root)   return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        findInorder(root, inorder);
        return inorder[k-1];
    }
};


// Time complexity O(k) space complexity O(1)
class Solution {
public:
    bool findInorder(TreeNode* root, int &k, int &ans)
    {
        if(!root)   return false;
        if(findInorder(root->left,k,ans))   return true;
        k--;
        if(k==0)
        {
            ans=root->val;
            k--;
            return true;
        }
        if(findInorder(root->right,k,ans))  return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        findInorder(root, k,ans);
        return ans;
    }
};