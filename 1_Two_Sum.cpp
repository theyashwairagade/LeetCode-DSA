// Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        for(int i=0;i<size;i++) for(int j=i+1;j<size;j++)
        if(nums[i]+nums[j]==target) return {i,j};
        return {};
    }
};


// Two pointer approach
class Solution {
public:
    int firstOccurence(vector<int> &vec,int target)
    {
        for(int i=0;i<vec.size();i++)   if(vec[i]==target)  return i;
        return -1;
    }
    int lastOccurence(vector<int> &vec,int target)
    {
        for(int i=vec.size()-1;i>=0;i--)   if(vec[i]==target)  return i;
        return -1;
    }
    vector<int> twoSum(vector<int>& vec, int target) {
        vector<int> nums=vec;
        sort(nums.begin(),nums.end());
        int left=0, right=nums.size()-1;
        while(left<right && left>=0)
        {
            int sum=nums[left]+nums[right];
            if(sum==target)  return {firstOccurence(vec,nums[left]),lastOccurence(vec,nums[right])};
            if(sum<target)  left++;
            else    right--;
        }
        return {};
    }
};

// Using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }
        return {}; // No solution found
    }
}; 