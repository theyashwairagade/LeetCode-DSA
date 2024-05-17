class Solution {
public:
    int minDifference(vector<int>& nums) {
        int length=nums.size();
        if(length<5)    return 0;
        sort(nums.begin(),nums.end());
        return min(min(nums[length-4]-nums[0],nums[length-1]-nums[3]),min(nums[length-3]-nums[1],nums[length-2]-nums[2]));
    }
};