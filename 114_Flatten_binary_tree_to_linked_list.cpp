// Time complexity of O(n) and space complexity of O(n)
class Solution {
public:
    TreeNode* prev;
    Solution(){prev=NULL;}
    void flatten(TreeNode* root) {
        if(!root)   return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

// Instead of recursion we can do similar with stack too with time complexity of O(n) and space complexity of O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *current=stk.top();
            stk.pop();
            if(current->right)  stk.push(current->right);
            if(current->left)   stk.push(current->left);
            if(!stk.empty())    current->right=stk.top();
            current->left=NULL;
        }
    }
};

// Optimal solution with time complexity of O(n) and space complexity of O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *current=root;
        while(current)
        {
            if(current->left)
            {
                auto prev=current->left;
                while(prev->right)
                    prev=prev->right;
                prev->right=current->right;
                current->right=current->left;
                current->left=NULL;
            }
            current=current->right;
        }
    }
};