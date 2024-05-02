class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(auto &c: s) mp[c]++;
        int occurence=mp[s[0]];
        for(auto &pr:mp)
            if(pr.second!=occurence)    return false;
        return true;
    }
};