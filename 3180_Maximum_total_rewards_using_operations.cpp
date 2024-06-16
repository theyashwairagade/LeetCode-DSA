// class Solution {
//     int solve(vector<vector<int>>& memo, vector<int>& vec, int x, int index) {
//         if (index < 0)
//             return 0;
//         if (memo[x][index] != -1)
//             return memo[x][index];
//         int take = 0, notTake = solve(memo, vec, x, index - 1);
//         if (vec[index] > x)
//             take = vec[index] + solve(memo, vec, x + vec[index], index - 1);
//         return memo[x][index] = max(take, notTake);
//     }

// public:
//     int maxTotalReward(vector<int>& vec) {
//         sort(vec.begin(), vec.end(), greater<int>());
//         int n = vec.size();
//         vector<vector<int>> memo(5000, vector<int>(n, -1)); // Initialize memoization table
//         return solve(memo, vec, 0, n - 1);
//     }
// };





// Using bottom up approach to reduce stack space
// class Solution {
// public:
//     int maxTotalReward(vector<int>& vec) {
//         sort(vec.begin(), vec.end(), greater<int>());
//         int n = vec.size();
//         vector<vector<int>> memo(4000, vector<int>(n + 1, 0)); // Initialize memoization table

//         // Fill the table from bottom up
//         for (int x = 3999; x >= 0; x--) 
//             for (int index = 1; index <= n; index++) {
//                 int notTake = memo[x][index - 1], take = 0;
//                 if (vec[index - 1] > x)
//                     take = vec[index - 1] + ((x + vec[index - 1] < 4000) ? memo[x + vec[index - 1]][index - 1] : 0);
//                 memo[x][index] = max(take, notTake);
//             }
//         return memo[0][n];
//     }
// };





// Space optimization from 2d array to 1d array
class Solution {
public:
    int maxTotalReward(vector<int>& vec) {
        sort(vec.begin(), vec.end(), greater<int>());
        int n = vec.size();
        vector<int> memo(4000); 

        // Fill the table from bottom up
        for (int x = 3999; x >= 0; x--) 
            for (int index = 0; index < n; index++) {
                int notTake = memo[x], take = 0;
                if (vec[index] > x)
                    take = vec[index] + ((x + vec[index] < 4000) ? memo[x + vec[index]] : 0);
                memo[x] = max(take, notTake);
            }
        return memo[0];
    }
};