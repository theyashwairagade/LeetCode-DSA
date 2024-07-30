// DP and memonization
class Solution {
    int solve(int index, int startedA, string &s, vector<vector<int>> &dp){
        if(!index)
            return (startedA && s[index]=='b');
        if(dp[index][startedA]!=-1)
            return dp[index][startedA];

        int remove = 1+solve(index-1, startedA, s, dp);
        int notRemove = ((!startedA) || s[index]=='a') ? solve(index-1, s[index]=='a', s, dp) : INT_MAX;
        return dp[index][startedA] = min(remove, notRemove);
    }
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(n-1, 0, s, dp);
    }
};





// Reduce stack space by giving iterative soln
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (2));
        for(int index = 0; index<n; index++)
            for(int startedA = 0; startedA<2; startedA++)
                if(index){
                    int remove = 1+dp[index-1][startedA];
                    int notRemove = ((!startedA) || s[index]=='a') ? dp[index-1][s[index]=='a'] : 10000000;
                    dp[index][startedA] = min(remove, notRemove);
                }
                else
                    dp[index][startedA]=(startedA && s[index]=='b');
        return dp[n-1][0];
    }
};





// Space optimization from O(2*n) to O(2)
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(2);
        for(int index = 0; index<n; index++)
            for(int startedA = 0; startedA<2; startedA++)
                if(index){
                    int remove = 1+dp[startedA];
                    int notRemove = ((!startedA) || s[index]=='a') ? dp[s[index]=='a'] : 10000000;
                    dp[startedA] = min(remove, notRemove);
                }
                else
                    dp[startedA]=(startedA && s[index]=='b');
        return dp[0];
    }
};