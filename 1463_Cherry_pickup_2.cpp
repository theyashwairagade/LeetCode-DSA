class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, int m, int row, int col1, int col2, vector<vector<vector<int>>>& dp) {
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1e9;
        if (row == n) return 0; // if we have processed all rows
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        int result = grid[row][col1];
        if (col1 != col2) result += grid[row][col2];
        
        int max_cherries = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                max_cherries = max(max_cherries, solve(grid, n, m, row + 1, col1 + d1, col2 + d2, dp));
            }
        }
        
        result += max_cherries;
        return dp[row][col1][col2] = result;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid, n, m, 0, 0, m - 1, dp);
    }
};





// To remove stack space i.e. to implement using tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for(int col1=0; col1<m; col1++)
            for(int col2=0; col2<m; col2++)
                dp[n-1][col1][col2]=grid[n-1][col1]+((col1==col2)?0:grid[n-1][col2]);
        for(int row=n-2; row>=0; row--)
            for(int col1=0; col1<m; col1++)
                for(int col2=0; col2<m; col2++)
                {
                    int result = grid[row][col1];
                    if (col1 != col2) result += grid[row][col2];

                    int max_cherries = 0;
                    for (int d1 = -1; d1 <= 1; d1++) 
                        for (int d2 = -1; d2 <= 1; d2++)
                            if(col1+d1>=0 && col2+d2>=0 && col1+d1<m && col2+d2<m)
                                max_cherries = max(max_cherries, dp[row+1][col1 + d1][ col2 + d2]);
                    
                    result += max_cherries;
                    dp[row][col1][col2] = result;
                }
        return dp[0][0][m-1];
    }
};





// It can be further optimized in terms of space complexity from O(m cube) to O(m square)