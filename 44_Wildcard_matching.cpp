class Solution {
public:
    bool solve(string &s, string &p, int index1, int index2, vector<vector<int>>& dp) {
        if (index2 < 0)
            return index1 < 0;

        if (index1 < 0) 
        {
            for (int i = 0; i <= index2; ++i)
                if (p[i] != '*') 
                    return false;
            return true;
        }

        if (dp[index1][index2] != -1) 
            return dp[index1][index2];

        if (p[index2] == s[index1] || p[index2] == '?')
            return dp[index1][index2] = solve(s, p, index1 - 1, index2 - 1, dp);

        if (p[index2] == '*') 
        {
            bool zeroCharacters=solve(s, p, index1, index2 - 1, dp);
            bool atLeastOneCharacter=solve(s, p, index1 - 1, index2, dp);
            return dp[index1][index2] = zeroCharacters || atLeastOneCharacter;
        }

        return dp[index1][index2] = false;
    }

    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return solve(s, p, len1 - 1, len2 - 1, dp);
    }
};
