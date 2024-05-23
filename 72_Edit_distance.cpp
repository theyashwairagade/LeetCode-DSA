// Brutte force will give tle
class Solution {
public:
    int solve(string &word1, string &word2, int index1, int index2)
    {
        if(index2<0)
            return index1+1;
        if(index1<0)
            return index2+1;

        if(word1[index1]==word2[index2])
            return solve(word1, word2, index1-1, index2-1);
        
        int insertOperation= solve(word1, word2, index1, index2-1);
        int deleteOperation= solve(word1, word2, index1-1, index2);
        int replaceOperation= solve(word1, word2, index1-1, index2-1);
        return 1+min(insertOperation,min(deleteOperation,replaceOperation));
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        return solve(word1, word2, len1-1, len2-1);
    }
};





// To perform overlapping subproblems in constant time do memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, string &word1, string &word2, int index1, int index2)
    {
        if(index2<0)
            return index1+1;
        if(index1<0)
            return index2+1;

        if(dp[index1][index2]!=-1)
            return dp[index1][index2];

        if(word1[index1]==word2[index2])
            return dp[index1][index2]= solve(dp, word1, word2, index1-1, index2-1);
        
        int insertOperation= solve(dp, word1, word2, index1, index2-1);
        int deleteOperation= solve(dp, word1, word2, index1-1, index2);
        int replaceOperation= solve(dp, word1, word2, index1-1, index2-1);
        return dp[index1][index2]= 1+min(insertOperation,min(deleteOperation,replaceOperation));
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        return solve(dp, word1, word2, len1-1, len2-1);
    }
};