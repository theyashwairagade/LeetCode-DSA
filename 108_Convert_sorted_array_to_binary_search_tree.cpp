class Solution {
public:
    TreeNode* binarySearchTree(vector<int>& nums,int start, int end)
    {
        if(start>end)   return NULL;
        if(start==end)  return new TreeNode(nums[start]);
        int mid=(start+end)/2;
        return new TreeNode(nums[mid], binarySearchTree(nums,start,mid-1),binarySearchTree(nums,mid+1,end));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binarySearchTree(nums,0,nums.size()-1);
    }
};