class Solution {
public:
    int minChanges(string s) {
        int ans=0, length=s.size();
        for(int i=1;i<length;i+=2)
            if(s[i]!=s[i-1])    ans++;
        return ans;
    }
};