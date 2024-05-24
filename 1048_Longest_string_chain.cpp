class Solution {
public:
    bool checkPossible(string &s1, string &s2) 
    {
        if (s1.size() != s2.size() + 1)
            return false;
        
        int second = 0;
        for(int first=0; first<s1.size();first++)
            if (second < s2.size() && s1[first] == s2[second]) 
                second++;
                
        return second == s2.size();
    }

    static bool comp(const string &s1, const string &s2) 
        {return s1.size() < s2.size();}

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < i; ++j) 
                if (checkPossible(words[i], words[j]) && 1 + dp[j] > dp[i]) 
                    maxi=max(maxi,dp[i] = dp[j] + 1);
        return maxi;
    }
};