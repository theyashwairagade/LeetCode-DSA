// Using hashmap with time complexity of O(n) and space complexity of O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>  mp;
        for(int num:nums)
        {
            mp[num]++;
            if(mp[num]>1)   return true;
        }
        return false;
    }
};


// Using sorting with time complexity of O(n logn) and space complexity of O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            if(nums[i-1]==nums[i])  return true;
        return false;
    }
};