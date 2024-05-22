// Brutte force will give tle
class Solution {
public:
    int solve(vector<int>& coins, int index, int amount)
    {
        if(!amount)
            return 0;
        if(!index)
            return (amount % coins[0]) ? 1e8 : amount / coins[0];
        int notTake=solve(coins, index-1, amount);
        int take= (amount<coins[index])?1e8:1+solve(coins, index, amount-coins[index]);
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)
            return 0;
        int n=coins.size();
        int ans=solve(coins, n-1, amount);
        return (ans && ans<1e8)?ans:-1;
    }
};





// To solve overlapping subproblem using memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int>& coins, int index, int amount)
    {
        if(!amount)
            return 0;
        if(!index)
            return (amount % coins[0]) ? 1e8 : amount / coins[0];
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int notTake=solve(dp, coins, index-1, amount);
        int take= (amount<coins[index])?1e8:1+solve(dp, coins, index, amount-coins[index]);
        return dp[index][amount]= min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)
            return 0;
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans=solve(dp, coins, n-1, amount);
        return (ans && ans<1e8)?ans:-1;
    }
};





// To save memory used by stack perform using tabulation





// optmize space complexity from O(amount*n) to O(amount)





// Reduce space complexity from O(2*amount) to O(amount)