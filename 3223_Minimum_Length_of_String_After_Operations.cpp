class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto &c: s)
            mp[c]++;
        int ans = 0;
        for(auto &pr: mp)
            if(pr.second%2)
                ans+=1;
            else
                ans+=2;
        return ans;
    }
};