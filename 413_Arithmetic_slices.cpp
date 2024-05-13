class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int length = nums.size(), dp=0, res = 0;
        for (int i = 2; i < length; i++)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                res += (++dp);
            else    dp=0;
        return res;
    }
};
