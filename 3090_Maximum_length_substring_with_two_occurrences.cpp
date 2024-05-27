class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) 
            {
                mp[s[j]]++;
                if(mp[s[j]]<3)  ans=max(ans,j-i+1);
                else break;
            }
        }
        return ans;
    }
};