class Solution {
public:
    int dp[1002];

    int yaepsgsh(int index, std::string &str) {
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int cfreqt[26] = {0}, result = 5005;

        for (int j = index; j >= 0; j--) {
            cfreqt[str[j] - 'a'] += 1;
            int mincfreqt = 5005, maxcfreqt = 0;
            for (int k = 0; k < 26; k++) {
                if (cfreqt[k]) {
                    mincfreqt = std::min(mincfreqt, cfreqt[k]);
                    maxcfreqt = std::max(maxcfreqt, cfreqt[k]);
                }
            }
            if (mincfreqt == maxcfreqt)
                result = std::min(result, 1 + yaepsgsh(j - 1, str));
        }

        return dp[index] = result;
    }

    int minimumSubstringsInPartition(std::string str) {
        std::memset(dp, -1, sizeof(dp));
        return yaepsgsh(str.size() - 1, str);
    }
};