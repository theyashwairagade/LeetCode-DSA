// Linear Search with time complexity of O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]==target)     return i;
        return -1;
    }
};





// Binary Search with time complexity of O(logn)
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool isSorted(int &start, int &end)
        {return end>=start;}
    bool inRange(int &start, int &end, int &target)
        {return start<=target && target<=end;}

    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=findMid(start,end);
            if(nums[mid]==target)   return mid;

            bool leftSorted=isSorted(nums[start],nums[mid]);
            if(leftSorted)
                if(inRange(nums[start],nums[mid],target))
                    end=mid-1;
                else
                    start=mid+1;
            else
                if(inRange(nums[mid],nums[end],target))
                    start=mid+1;
                else
                    end=mid-1;
        }
        return -1;
    }
};