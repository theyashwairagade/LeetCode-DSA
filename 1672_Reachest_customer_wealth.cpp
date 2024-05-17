class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(vector<int> a:accounts)
            ans=max(ans,accumulate(a.begin(),a.end(),0));
        return ans;
    }
};