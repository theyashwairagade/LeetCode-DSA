// Front partitioning will give tle
class Solution {
public:
    bool wordExists(string &s, unordered_map<string,bool> &mp, int start, int end)
        {return mp[s.substr(start,end-start+1)];}
    bool solve(string &s, unordered_map<string,bool> &mp, int start, int end)
    {
        if(wordExists(s, mp, start, end))
            return true;
        
        for(int i=start; i<end; i++)
            if(wordExists(s, mp, start, i) && solve(s, mp, i+1, end))
                return true;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        for(auto &str: wordDict)
            mp[str]=true;
        
        int n=s.size();
        return solve(s, mp, 0, n-1);
    }
};





// To solve overlapping subproblems in constant time use memorization
class Solution {
public:
    bool wordExists(string &s, unordered_map<string,bool> &mp, int start, int end)
        {return mp[s.substr(start,end-start+1)];}
    bool solve(vector<vector<int>> &dp, string &s, unordered_map<string,bool> &mp, int start, int end)
    {
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(wordExists(s, mp, start, end))
            return dp[start][end]= true;
        
        for(int i=start; i<end; i++)
            if(wordExists(s, mp, start, i) && solve(dp, s, mp, i+1, end))
                return dp[start][end]= true;
        return dp[start][end]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        for(auto &str: wordDict)
            mp[str]=true;
        
        int n=s.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(dp, s, mp, 0, n-1);
    }
};