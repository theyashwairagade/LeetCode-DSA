class Solution {
    int parity(int a)
        {return a%2;}
    bool different(int a, int b)
        {return a != b;}
    long long solve(vector<vector<long long>> &dp, vector<int> &nums, int &x, int index, int prevParity){
        if(dp[index][prevParity]!=-1)
            return dp[index][prevParity];

        if(index == nums.size()-1)
            return dp[index][prevParity]= max(0, nums[index] + (different(parity(nums[index]),prevParity) ? -x : 0));
        long long take = nums[index] + (different(parity(nums[index]),prevParity) ? -x : 0) + solve(dp, nums, x, index+1, parity(nums[index]));
        long long notTake = solve(dp, nums, x, index+1, prevParity);
        return dp[index][prevParity]= max(take, notTake);
    }
public:
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        return solve(dp, nums, x, 0, parity(nums[0]));
    }
};