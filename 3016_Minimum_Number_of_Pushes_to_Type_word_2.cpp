class Solution {
public:
    int minimumPushes(string word) {
        vector<int> dp(26, 0);
        for(auto &c: word)
            dp[c-'a']++;
        
        sort(dp.begin(), dp.end(), greater<int> ());
        int ans = 0;

        for(int i=0; i<8; i++)
            ans+=dp[i];
        for(int i=8; i<16; i++)
            ans+=dp[i]*2;
        for(int i=16; i<24; i++)
            ans+=dp[i]*3;
        ans+=dp[24]*4;
        ans+=dp[25]*4;

        return ans;
    }
};