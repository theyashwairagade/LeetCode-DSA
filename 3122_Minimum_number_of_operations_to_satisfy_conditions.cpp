// Brutte gives tle
// class Solution {
// public:
//     int costToChange(vector<vector<int>> &grid, int col, int digit)
//     {
//         int cost=0;
//         int n=grid.size();
//         for(int i=0; i<n; i++)
//             if(grid[i][col]!=digit)
//                 cost++;
//         return cost;
//     }
//     int solve(vector<vector<int>> &grid, int col, int prev)
//     {
//         if(col<0)
//             return 0;
//         int ans=INT_MAX;
//         for(int digit=0; digit<10; digit++)
//             if(digit!=prev)
//                 ans=min(ans, costToChange(grid, col, digit)+ solve(grid, col-1, digit));
//         return ans;
//     }
//     int minimumOperations(vector<vector<int>>& grid) {
//         int n=grid.size(), m=grid[0].size();
//         return solve(grid, m-1, -1);
//     }
// };





// To solve overlapping subproblems in constant time perform memorization
class Solution {
public:
    int costToChange(vector<vector<int>> &grid, int col, int digit)
    {
        int cost=0;
        int n=grid.size();
        for(int i=0; i<n; i++)
            if(grid[i][col]!=digit)
                cost++;
        return cost;
    }
    int solve(vector<vector<int>> &dp, vector<vector<int>> &grid, int col, int prev)
    {
        if(col<0)
            return 0;
        int ans=INT_MAX;
        for(int digit=0; digit<10; digit++)
            if(digit!=prev)
            {
                if(dp[col][digit]==-1)
                    dp[col][digit]=costToChange(grid, col, digit)+ solve(dp, grid, col-1, digit);
                ans=min(ans,dp[col][digit]);
            }
        return ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(10,-1));
        return solve(dp, grid, m-1, -1);
    }
};