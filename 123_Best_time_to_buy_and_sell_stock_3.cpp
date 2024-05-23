class Solution {
public:
    int solve(vector<int> &prices, int n, int index, int attempts, bool hasStock, vector<vector<vector<int>>> &dp) {
        if (attempts == 0)
            return 0;
        if (index == n)
            return 0;

        if (dp[index][attempts][hasStock] != -1)
            return dp[index][attempts][hasStock];

        int ignore = solve(prices, n, index + 1, attempts, hasStock, dp);
        if (hasStock) {
            int sell = solve(prices, n, index + 1, attempts - 1, false, dp) + prices[index];
            dp[index][attempts][hasStock] = max(sell, ignore);
        } else {
            int buy = solve(prices, n, index + 1, attempts, true, dp) - prices[index];
            dp[index][attempts][hasStock] = max(buy, ignore);
        }
        return dp[index][attempts][hasStock];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int attempts = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(attempts + 1, vector<int>(2, -1)));
        return solve(prices, n, 0, attempts, false, dp);
    }
};
