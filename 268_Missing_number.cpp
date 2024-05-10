class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=nums.size();
        for(int i=ans-1;i>=0;i--)
            ans^=(i^nums[i]);
        return ans;
    }
};