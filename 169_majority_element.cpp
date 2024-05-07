// Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element, count=0;
        for(int number:nums)
        {   if(!count)  element=number;
            if(element==number) count++;
            else    count--;
        }
        return element;
    }
};

// Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

// Hash map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums)   mp[num]++;
        int len=nums.size()/2;
        for(auto mping:mp)  if(mping.second>len)  return mping.first;
        return -1;
    }
};

// Hash map sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums)   mp[num]++;
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(),vec.end(),[] (const pair<int,int> &a, const pair<int,int> &b)
        {
            return a.second>b.second;
        });
        return vec[0].first;
    }
};