class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        for(int i=0;i<s.length()-1;i++)
            if(toupper(s[i+1])!=toupper(s[i]))   ans++;
        return ans;
    }
};