// Brutte
class Solution {
    int findMid(int a, int b)
        {return a+(b-a)/2;}
    void solve(TreeNode* root, vector<int> &array)
    {
        if(!root)
            return;
        solve(root->left, array);
        array.push_back(root->val);
        solve(root->right, array);
    }
    TreeNode* solve(vector<int> &array, int left, int right)
    {
        if(left>right)
            return NULL;
        if(left==right)
            return new TreeNode(array[left]);

        int mid = findMid(left, right);
        return new TreeNode(array[mid], solve(array, left, mid-1), solve(array, mid+1, right));
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> array;
        solve(root, array);
        return solve(array, 0, array.size()-1);
    }
};





// Space complexity can be optimized using Day Stout Warren (DSW) Algorithm