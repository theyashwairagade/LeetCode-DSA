// class Solution {
//     int solve(vector<vector<int>> &dp, vector<int> &nums, int index, int prev)
//     {
//         if(dp[index][prev-1]!=-1)
//             return dp[index][prev-1];
//         if(!index)
//             return dp[index][prev-1] = nums[index]<=prev;
//         int notTake = solve(dp, nums, index-1, prev);
//         if(nums[index]>prev)
//             return dp[index][prev-1]= notTake;
//         int take = 1+solve(dp, nums, index-1, nums[index]);
//         return dp[index][prev-1]= max(take, notTake);
//     }
// public:
//     int minimumOperations(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(3,-1));
//         return n-solve(dp, nums, n-1, 3);
//     }
// };





// Can be done in bottom up approach





// Space optimization can be done to O(1)