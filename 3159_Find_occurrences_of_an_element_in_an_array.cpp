class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int index=1;

        for(int i=0;i<n;i++)
            if(nums[i]==x)
                mp[index++]=i;
        
        for(auto &query: queries)
            if(mp.find(query)!=mp.end())
                query=mp[query];
            else
                query=-1;
        return queries;
    }
};