// DFS
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (!root) 
//             return false;
        
//         if (root->left || root->right)
//             return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        
//         return targetSum == root->val;
        
//     }
// };

// BFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) 
            return false;
        
        queue<pair<TreeNode*, int>> q;

        q.push(make_pair(root,root->val));
        while(!q.empty())
        {
            // TreeNode* node;
            // int currentSum;
            // tie(node, currentSum) = q.front();
            auto [node, currentSum] = q.front();
            q.pop();
            if(node->left)
                q.push(make_pair(node->left,currentSum+node->left->val));
            if(node->right)
                q.push(make_pair(node->right,currentSum+node->right->val));
            if(!node->left && !node->right && currentSum==targetSum)    return true;
        }
        return false;
    }
};