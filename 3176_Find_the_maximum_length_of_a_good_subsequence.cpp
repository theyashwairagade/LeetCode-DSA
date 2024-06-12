class Solution {
    int solve(vector<vector<int>> &dp, vector<int> &nums, int k,int index)
    {
        if(k<0)
            return -1;
        if(dp[k][index]!=-1)
            return dp[k][index];
        int ans=0;
        for(int i=0; i<index; i++)
            if(nums[i]==nums[index])
                ans=max(ans, 1+solve(dp, nums,k,i));
            else
                ans=max(ans, 1+ solve(dp, nums, k-1, i));
        return dp[k][index]= ans;
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1;
        vector<vector<int>> dp(26, vector<int> (n,-1));
        for(int i=1; i<n; i++)
            ans=max(ans,1+solve(dp,nums, k ,n-i));
        return ans;
    }
};