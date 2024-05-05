class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        int n=word.size();
        for(int i=0;i<n;i+=k)
            mp[word.substr(i,k)]++;
        
        int ans=0;
        for(const auto &pr:mp)
            ans=max(ans,pr.second);
        return (n/k)-ans;
    }
};