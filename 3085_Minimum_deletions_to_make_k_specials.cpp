class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &freq, int &k, int start, int end)
    {
        if(start>=end)
            return 0;
        
        if(dp[start][end]!=-1)
            dp[start][end];
        if(freq[start]<=k+freq[end])
            return dp[start][end]= 0;
        
        int deletingStart= freq[start]-k-freq[end] + solve(dp, freq, k, start+1, end);
        int deletingEnd= freq[end]+solve(dp, freq, k, start, end-1);
        return dp[start][end]= min(deletingStart, deletingEnd);
    }
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(auto &c: word)
            freq[c-'a']++;
        
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        for(int i=25; i>=0; i--)
            if(!freq[i])
                freq.pop_back();
            else
                break;
        
        vector<vector<int>> dp(26, vector<int> (26, -1));
        return solve(dp, freq, k, 0, freq.size()-1);
    }
};