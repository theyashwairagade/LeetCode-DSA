class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1, mp2;

        for(auto &i: words1)
            mp1[i]++;
        
        for(auto &i: words2)
            mp2[i]++;
        
        int ans=0;
        for(auto &pr: mp1)
            if(pr.second==1 && mp2[pr.first]==1)
                ans++;
            
        return ans;
    }
};