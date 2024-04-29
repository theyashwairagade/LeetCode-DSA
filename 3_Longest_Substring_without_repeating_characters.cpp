class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> mp;
        int left=0, right=0, n=s.size(),ans=0;
        while(right<n)
        {
            while(right<n && mp[s[right]]==false)
            {
                ans=max(ans,right-left+1);
                mp[s[right]]=true;
                right++;
            }
            while(s[left]!=s[right])
            {
                mp[s[left]]=false;
                left++;
            }
            if (left < right && s[left] == s[right])    left++; // I failed in this line
            right++; // I failed in this line
        }
        return ans;
    }
};