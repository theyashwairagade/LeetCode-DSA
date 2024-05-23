class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &prices, int &n, int &fee, int index, bool hasStock)
    {
        if(index>=n)
            return 0;
        if(dp[index][hasStock]!=-1)
            return dp[index][hasStock];
        int ignore=solve(dp, prices, n, fee, index+1, hasStock);
        if(hasStock)
        {
            int sell= prices[index] - fee + solve(dp, prices, n, fee, index+1, !hasStock);
            return dp[index][hasStock]= max(ignore,sell);
        }
        int buy=-prices[index]+solve(dp, prices, n, fee, index+1, !hasStock);
        return dp[index][hasStock]= max(ignore, buy);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size(), startingIndex=0;
        bool hasStock=false;
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(dp, prices, n, fee, startingIndex, hasStock);
    }
};