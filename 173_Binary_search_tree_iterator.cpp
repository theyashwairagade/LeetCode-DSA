class BSTIterator {
public:
    int iterator, n;
    vector<int> vec;

    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (!root)    return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    BSTIterator(TreeNode* root) {
        inorderTraversal(root,vec);
        iterator=0;
        n=vec.size();
    }
    
    int next() {
        return vec[iterator++];
    }
    
    bool hasNext() {
        if(iterator<n)  return true;
        return false;
    }
};