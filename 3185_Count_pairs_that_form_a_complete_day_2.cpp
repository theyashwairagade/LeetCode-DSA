class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;
        long long ans= 0;
        for(auto &i: hours)
        {
            int have = i % 24;
            int want = 24 - have;
            want %= 24;
            ans += mp[want];
            mp[have]++;
        }
        return ans;
    }
};