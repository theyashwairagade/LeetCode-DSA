class Solution {
public:
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int &index)
    {
        if(start>end)   return NULL;
        int rootVal=postorder[index--],i;
        for(i=start;i<=end;i++)
            if(inorder[i]==rootVal)   break;
        TreeNode * root=new TreeNode(rootVal);
        root->right=solve(inorder,postorder,i+1,end,index);
        root->left=solve(inorder,postorder,start,i-1,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=inorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1,index);
    }
};