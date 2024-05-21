class Solution {
public:
    long long minimumCost(string s) {
        long long int ans=0;
        int n=s.size();
        for(int i=1;i<n;i++)
            if(s[i-1]!=s[i])    ans+=min(i,n-i);
        return ans;
    }
};