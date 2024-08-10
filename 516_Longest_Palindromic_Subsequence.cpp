class Solution {
    int solve(vector<vector<int>> &dp, string &str1, string &str2, int index1,int index2)
    {
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(!index1 && !index2)
            return dp[index1][index2] = str1[index1]==str2[index2];
        if(!index1)
            return dp[index1][index2] = (str1[index1]==str2[index2]) ? 1 : solve(dp, str1, str2, index1, index2-1);
        if(!index2)
            return dp[index1][index2] = (str1[index1]==str2[index2]) ? 1: solve(dp, str1, str2, index1-1, index2);

        if(str1[index1]==str2[index2])
            return dp[index1][index2] = 1+solve(dp, str1, str2, index1-1, index2-1);
        return dp[index1][index2] = max(solve(dp, str1, str2, index1-1, index2), solve(dp, str1, str2, index1, index2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size(), size2=text2.size();
        vector<vector<int>> dp(size1, vector<int> (size2, -1));
        return solve(dp, text1, text2, size1-1, size2-1);
    }
public:
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return longestCommonSubsequence(s, temp);
    }
};