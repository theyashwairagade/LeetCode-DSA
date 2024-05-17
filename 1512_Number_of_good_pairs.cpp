class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int a:nums)
        {
            if(mp.count(a)==0) mp[a]++;
            else    ans+=(mp[a]++);
        }
        return ans;
    }
};