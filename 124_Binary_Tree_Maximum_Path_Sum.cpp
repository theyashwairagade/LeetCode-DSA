class Solution {
    pair<int,int> solve(TreeNode* root){
        if(!root)
            return {INT_MIN, INT_MIN};
        auto lft = solve(root->left),
             rht = solve(root->right);
        int scd = root->val + max(0, max(lft.second, rht.second));

        int fst = INT_MIN;
        fst = max(fst, lft.first);
        fst = max(fst, rht.first);
        fst = max(fst, root->val + max(lft.second, 0) + max(rht.second, 0));
        return {fst, scd};
    }
public:
    int maxPathSum(TreeNode* root) {
        return solve(root).first;
    }
};