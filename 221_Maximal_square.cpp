class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));

        int ans = 0;
        for(int i = n-1; i>=0; i--)
            for(int j = m-1; j>=0; j--)
                if(matrix[i][j]=='1')
                {
                    int right = (j+1<m) ? dp[i][j+1] : 0;
                    int bottom = (i+1<n) ? dp[i+1][j] : 0;
                    int bottomRight = (i+1<n && j+1<m) ? dp[i+1][j+1] : 0;
                    ans = max(ans, dp[i][j] = 1+ min(right, min(bottom, bottomRight)));
                }
        return ans*ans;
    }
};

// above code can be space optimized too