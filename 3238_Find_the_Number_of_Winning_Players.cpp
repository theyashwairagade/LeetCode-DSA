class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> dp(n, vector<int> (11, 0));

        for(auto &entry: pick){
            int player = entry[0], color = entry[1];
            dp[player][color]++;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<11; j++)
                if(dp[i][j]>i){
                    ans++;
                    break;
                }
        }
        return ans;
    }
};