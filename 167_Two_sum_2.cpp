// Two pointers approach in time complexity of O(n) and space of O(1)
class Solution {
public:
    int firstOccurence(vector<int> &vec,int target)
    {
        for(int i=0;i<vec.size();i++)   if(vec[i]==target)  return i+1;
        return -1;
    }
    int lastOccurence(vector<int> &vec,int target)
    {
        for(int i=vec.size()-1;i>=0;i--)   if(vec[i]==target)  return i+1;
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<right && left>=0)
        {
            int sum=nums[left]+nums[right];
            if(sum==target)  return {firstOccurence(nums,nums[left]),lastOccurence(nums,nums[right])};
            if(sum<target)  left++;
            else    right--;
        }
        return {};
    }
};


// Using hash table in time complexity of O(n) and space complexity of O(n)
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
                return {i+1, numMap[complement]+1};
            }
        }
        return {}; // No solution found
    }
};