class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(!root)
            return {0,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        int nodeSum= left.first+right.first+root->val;
        int nodeAbsSum= left.second+right.second+abs(left.first-right.first);
        return {nodeSum, nodeAbsSum};
    }
    int findTilt(TreeNode* root) {
        return solve(root).second;
    }
};





// We can save more memory space if we use concept of global variable to store ans