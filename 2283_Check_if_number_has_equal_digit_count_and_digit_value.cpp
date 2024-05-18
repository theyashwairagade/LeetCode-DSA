class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mp;
        for(const auto &c: num)
            mp[c-'0']++;
        int n=num.size();
        for(int i=0;i<n;i++)
            if(mp[i]!=num[i]-'0')   return false;
        return true;
    }
};