// Brutte force
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, INT_MIN));

        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--)
            {
                for(int row=n-1; row>i; row--)
                {
                    int valOfCurrentStep= grid[row][j] - grid[i][j];
                    int valueOfNextStep= dp[row][j];

                    if(valueOfNextStep>0)
                        valOfCurrentStep+=valueOfNextStep;
                    dp[i][j]=max(dp[i][j],valOfCurrentStep);
                }

                for(int col=m-1; col>j; col--)
                {
                    int valueOfCurrentStep= grid[i][col] - grid[i][j];
                    int valueOfNextStep= dp[i][col];

                    if(valueOfNextStep>0)
                        valueOfCurrentStep+=valueOfNextStep;
                    dp[i][j]=max(dp[i][j],valueOfCurrentStep);
                }
            }

        int ans=INT_MIN;
        for(auto &vec: dp)
            for(auto &i: vec)
                ans=max(ans, i);
        return ans;
    }
};





class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, INT_MIN));

        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--)
            {
                if(i+1<n)
                {
                    int valueOfCurrentStep=grid[i+1][j]-grid[i][j];
                    if(dp[i+1][j]>0)
                        valueOfCurrentStep+=dp[i+1][j];
                    dp[i][j]=max(dp[i][j], valueOfCurrentStep);
                }

                if(j+1<m)
                {
                    int valueOfCurrentStep=grid[i][j+1]-grid[i][j];
                    if(dp[i][j+1]>0)
                        valueOfCurrentStep+=dp[i][j+1];
                    dp[i][j]=max(dp[i][j], valueOfCurrentStep);
                }
            }

        int ans=INT_MIN;
        for(auto &vec: dp)
            for(auto &i: vec)
                ans=max(ans, i);
        return ans;
    }
};