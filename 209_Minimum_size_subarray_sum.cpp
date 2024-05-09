class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, ans=INT_MAX;
        int left=0,right=0;
        while(right<nums.size())
        {
            while(sum<target && right<nums.size())
                sum+=nums[right++];
            while(sum>=target)
            {
                ans=min(ans,right-left);
                sum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};