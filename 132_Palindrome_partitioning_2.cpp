// Front Partitioning approach will give tle
class Solution {
public:
    bool stringPalindrome(string &s, int start, int end)
    {
        while(start<end)
            if(s[start++]!=s[end--])
                return false;
        return true;
    }
    int solve(string &s, int start, int end)
    {
        if(stringPalindrome(s, start, end))
            return 0;
        
        int ans=end-start;
        for(int i=start; i<end; i++)
            if(stringPalindrome(s, start, i))
                ans=min(ans, 1+solve(s, i+1, end));
        return ans;
    }
    int minCut(string s) {
        int n=s.size();
        return solve(s, 0, n-1);
    }
};





// To solve overlapping subproblems perform memorization
class Solution {
public:
    bool stringPalindrome(string &s, int start, int end)
    {
        while(start<end)
            if(s[start++]!=s[end--])
                return false;
        return true;
    }
    int solve(vector<vector<int>> &dp, string &s, int start, int end)
    {
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        if(stringPalindrome(s, start, end))
            return dp[start][end]= 0;

        int ans=end-start;
        for(int i=start; i<end; i++)
            if(stringPalindrome(s, start, i))
                ans=min(ans, 1+solve(dp, s, i+1, end));
        return dp[start][end]= ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(dp, s, 0, n-1);
    }
};