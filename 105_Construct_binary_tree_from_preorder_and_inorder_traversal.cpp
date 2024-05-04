class Solution {
public:
    TreeNode* solve(vector<int> preorder, vector<int> inorder, int start, int end, int &index)
    {
        if(start>end)   return NULL;
        int rootVal=preorder[index], i=start;
        for(;i<=end;i++)
            if(inorder[i]==rootVal) break;
        index++;
        return new TreeNode(rootVal,solve(preorder,inorder,start,i-1,index),solve(preorder,inorder,i+1,end,index));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return solve(preorder,inorder,0,preorder.size()-1,index);
    }
};