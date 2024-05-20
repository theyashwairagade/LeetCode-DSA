class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[m-1][n-1] = obstacleGrid[m-1][n-1] == 1 ? 0 : 1;

        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if(i < m-1) {
                        dp[i][j] += dp[i+1][j];
                    }
                    if(j < n-1) {
                        dp[i][j] += dp[i][j+1];
                    }
                }
            }
        }

        return dp[0][0];
    }
};
