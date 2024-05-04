// Recursive DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
// We can do by iterative too by using stack


// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)   return 0;
        q.push(root);
        q.push(NULL);
        int len=1;
        while(q.size()>1)
        {
            if(!q.front())
                q.pop(),q.push(NULL),len++;
            else
            {
                if(q.front()->left)     q.push(q.front()->left);
                if(q.front()->right)    q.push(q.front()->right);
                q.pop();
            }
        }
        return len;
    }
};
