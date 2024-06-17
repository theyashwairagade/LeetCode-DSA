// I copied from aryan mittal but this comes under later
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // doing work of sorting and hash table for counting
        map <long long, long long> freq;
        for(auto &i: power)
            freq[i]++;
        
        // dynamic programming
        unordered_map <int, long long> dp;
        long long n = power.size(), ans = 0, prev, back = 0;
        for (auto [i, freqOfI] : freq) {
            // binary search
            auto backIt = freq.lower_bound(i-2);
            if(backIt != freq.begin())
                back = (*(--backIt)).first;
            dp[i] = max (dp[prev], i * freqOfI + dp[back]);
            ans = max (ans, dp[i]);
            prev = i;
        }
        return ans;
    }
};