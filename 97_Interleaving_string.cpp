class Solution {
    bool solve(vector<vector<int>> &dp, int first, int second, string &s1, string &s2, string &s3){
        if(dp[first][second]!=-1)
            return dp[first][second];
        if(first == s1.size() && second == s2.size())
            return dp[first][second]= true;
        if(first < s1.size() && s1[first]== s3[first+second] && solve(dp, first+1, second, s1, s2, s3))
            return dp[first][second]= true;
        if(second < s2.size() && s2[second] == s3[first + second] && solve(dp, first, second+1, s1, s2, s3))
            return dp[first][second]= true;
        return dp[first][second]= false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        return solve(dp, 0, 0, s1, s2, s3);
    }
};