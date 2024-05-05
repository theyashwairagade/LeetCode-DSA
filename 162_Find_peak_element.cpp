// Linear Search with time complexity of O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-2]<nums[n-1])
            return n-1;
        for(int i=1;i+1<n;i++)
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
                return i;
        return -1;
    }
};





// Binary Search 
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool equal(int &start, int &end)
        {return start==end;}
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-2]<nums[n-1])
            return n-1;
        
        // Solving for one peak element is the solution
        int start=1, end=n-2;
        while(start<=end)
        {
            if(equal(start,end))  return start;

            int mid=findMid(start,end);
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                return mid;
            if(nums[mid-1]<nums[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};