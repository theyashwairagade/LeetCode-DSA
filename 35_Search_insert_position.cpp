class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end=nums.size();
        if(target>nums[end-1])  return end;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)   return mid;
          
            if(target<nums[mid])    end=mid-1;    
            else    start=mid+1;        
        }
        return  start;   
    }
};