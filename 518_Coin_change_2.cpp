// Brutte Force will give tle
class Solution {
public:
    int solve(vector<int> &coins, int index, int amount)
    {
        if(!amount)
            return 1;
        if(!index)
            return (amount<coins[index]) ? 0 : solve(coins, index, amount-coins[index]);

        int notTake=solve(coins, index-1, amount);
        int take=0;
        if(amount>=coins[index])
            take=solve(coins, index, amount-coins[index]);
        return take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(coins, n-1, amount);
    }
};





// To solve overlapping subproblems in constant time use memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &coins, int index, int amount)
    {
        if(!amount)
            return 1;
        if(!index)
            return (amount<coins[index]) ? 0 : solve(dp, coins, index, amount-coins[index]);
        
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int notTake=solve(dp, coins, index-1, amount);
        int take=(amount<coins[index]) ? 0 : solve(dp, coins, index, amount-coins[index]);
        return dp[index][amount]= take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(dp, coins, n-1, amount);
    }
};





// To save space taken from recursion solve question using tabulation
class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (target+1,0));

        for(int index=0; index<n; index++)
            dp[index][0]=1;
        
        for(int amount=1; amount<=target; amount++)
            if(amount%coins[0]==0)
                dp[0][amount]=1;
            
        for(int index=1; index<n; index++)
            for(int amount=1; amount<=target; amount++)
            {
                int notTake=dp[index-1][amount];
                int take=(amount<coins[index]) ? 0 : dp[index][amount-coins[index]];
                dp[index][amount]=(take+notTake);
            }
        return dp[n-1][target];
    }
};





// Reducing space complexity from O(n*target) to O(target)
class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(target+1, 0);
        dp[0]=1;
            
        for(int amount=1; amount<=target; amount++)
            if(amount%coins[0]==0)
                dp[amount]=1;

        for(int index=1; index<n; index++)
            for(int amount=1; amount<=target; amount++)
            {
                int notTake=dp[amount];
                int take=(amount<coins[index]) ? 0 : dp[amount-coins[index]];
                dp[amount]=(take+notTake);
            }
        return dp[target];
    }
};