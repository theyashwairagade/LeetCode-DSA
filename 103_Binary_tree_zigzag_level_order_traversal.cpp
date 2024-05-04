class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true; // Indicates the direction of traversal

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> temp(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* top = q.front();
                q.pop();

                int index = leftToRight ? i : (levelSize - 1 - i);
                temp[index] = top->val;

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            ans.push_back(temp);
            leftToRight = !leftToRight; // Reverse the direction for the next level
        }

        return ans;
    }
};