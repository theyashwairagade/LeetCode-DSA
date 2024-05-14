class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++)
            mp[s[i]]=i;
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(mp[t[i]]-i);
        return ans;
    }
};