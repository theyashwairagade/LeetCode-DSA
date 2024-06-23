class Solution {
    int even(int a){
        if(a%2)
            return a-1;
        return a;
    }
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &c: s)
            mp[c]++;
        
        bool odd = false;
        int ans = 0;
        for(auto &pr: mp)
        {
            ans += even(pr.second);
            if(pr.second%2)
                odd = true;
        }
        if(odd)
            ans++;
        return ans;
    }
};