class Solution {
public:
    int longestPalindromicSequence(int ind1,int ind2,string &s,string &rev, vector<vector<int>> &dp) {
        if(ind1<0 or ind2<0)    return 0; 
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        if(s[ind1]==rev[ind2])
            return dp[ind1][ind2]=1+longestPalindromicSequence(ind1-1,ind2-1,s,rev,dp);
        return dp[ind1][ind2]=max(longestPalindromicSequence(ind1-1,ind2,s,rev,dp),longestPalindromicSequence(ind1,ind2-1,s,rev,dp));
    }

    int minInsertions(string s) {
        int n=s.length();
        string rev=s; 
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-longestPalindromicSequence(n-1,n-1,s,rev,dp);
    }
};