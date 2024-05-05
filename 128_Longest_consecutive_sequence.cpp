class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(const int &num:nums) mp[num]=true;
        
        int ans=0;
        for(const int &num:nums)
            if(!mp[num-1])
            {
                int length=0;
                while(mp[num+length])
                    length++;
                ans=max(ans,length);
            }
        return ans;
    }
};