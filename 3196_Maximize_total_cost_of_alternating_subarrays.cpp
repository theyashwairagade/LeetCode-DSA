class Solution {
    long long solve(vector<vector<long long>> &dp, vector<int> &nums, int negative, int i)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i][negative]!=-1)
            return dp[i][negative];
        long long ans;
        if(negative)
            ans = -nums[i] + solve(dp, nums, 0, i+1);
        else
            ans = nums[i] + max(solve(dp, nums, 0, i+1), solve(dp, nums, 1, i+1));
        return dp[i][negative]=ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return solve(dp, nums, 0, 0);
    }
};