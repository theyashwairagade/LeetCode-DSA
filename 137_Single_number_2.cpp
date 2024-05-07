class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int ans=0;
        for(const int &num: nums)
        {
            if(!mp[num])
                ans^=num;
            mp[num]=!mp[num];
        }
        return ans;
    }
};


// You can't find this solution on time you need to remember this
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for(const auto &num: nums)
        {
            ones=(ones ^ num) & ~twos;
            twos=(twos ^ num) & ~ones;
        }
        return ones;
    }
};