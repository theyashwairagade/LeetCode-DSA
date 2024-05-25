// Brutte force will give tle
class Solution {
public:
    int solve(vector<int> &nums, int start, int end)
    {
        if(start>end)
            return 0;
        if(start==end)
            return nums[start-1]*nums[start]*nums[end+1];
        
        int maxAns=INT_MIN;
        for(int i=start;i<=end; i++)
        {
            int ans=solve(nums, start, i-1) + nums[start-1]*nums[i]*nums[end+1] + solve(nums, i+1, end);
            maxAns=max(maxAns, ans);
        }
        return maxAns;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(nums, 1, n);
    }
};





// To solve overlapping subproblems in constant time use memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &nums, int start, int end)
    {
        if(start>end)
            return 0;
        
        if(dp[start-1][end-1]!=-1)
            return dp[start-1][end-1];

        if(start==end)
            return dp[start-1][end-1]= nums[start-1]*nums[start]*nums[end+1];
        
        int maxAns=INT_MIN;
        for(int i=start;i<=end; i++)
        {
            int ans=solve(dp, nums, start, i-1) + nums[start-1]*nums[i]*nums[end+1] + solve(dp, nums, i+1, end);
            maxAns=max(maxAns, ans);
        }
        return dp[start-1][end-1]= maxAns;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(dp, nums, 1, n);
    }
};