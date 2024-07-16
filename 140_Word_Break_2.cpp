class Solution {
    void solve(string s, vector<string> &dict, unordered_map<string, vector<string>> &dp){
        if(dp.find(s)!=dp.end())
            return;
        if(s.empty()){
            dp[s]={""};
            return;
        }

        vector<string> ans; 
        for(auto &word: dict){
            int len = word.size();
            string iGot = s.substr(0,len);

            if(iGot != word)
                continue;
            
            string remaining = s.substr(len);
            solve(remaining, dict, dp);

            for(auto &remAns: dp[remaining])
                ans.push_back(word + (remAns.size() ? " " : "") + remAns);
        }
        dp[s]=ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> dp;
        solve(s, wordDict, dp);
        return dp[s];
    }
};