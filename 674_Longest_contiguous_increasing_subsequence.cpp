class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1, current=1, length=nums.size();
        for(int i=1;i<length;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                ans=max(ans,current);
                current=0;
            }
            current++;
        }
        ans=max(ans,current);
        return ans;
    }
};