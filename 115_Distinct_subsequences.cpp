// Brute Force will give TLE
class Solution {
public:
    int solve(string &str1, string &str2, int index1, int index2)
    {
        if(index2<0)
            return 1;
        if(index1<0)
            return 0;
        if(index1<index2)
            return 0;
        
        int notTake=solve(str1, str2, index1-1, index2);
        int take=0;
        if(str1[index1]==str2[index2])
            take=solve(str1, str2, index1-1, index2-1);
        return take+notTake;
    }
    int numDistinct(string s, string t) {
        int len1=s.size(), len2=t.size();
        return solve(s, t, len1-1, len2-1);
    }
};





// To solve overlapping subproblems in constant time implement memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, string &str1, string &str2, int index1, int index2)
    {
        if(index2<0)
            return 1;
        if(index1<0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(index1<index2)
            return dp[index1][index2]= 0;
        
        int notTake=solve(dp, str1, str2, index1-1, index2);
        int take= (str1[index1]!=str2[index2])?0: solve(dp, str1, str2, index1-1, index2-1);
        return dp[index1][index2]= take+notTake;
    }
    int numDistinct(string s, string t) {
        int len1=s.size(), len2=t.size();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        return solve(dp, s, t, len1-1, len2-1);
    }
};