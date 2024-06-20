class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n=nums.size(), half= nums.size()/2;
        double ans = nums[n-1];
        for(int i=0; i<half; i++)
            ans = min(ans, ((double) nums[i]+nums[n-i-1])/2);
        return ans;
    }
};