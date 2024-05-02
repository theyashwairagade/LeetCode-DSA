class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool isSorted(int &start, int &end)
        {return end>=start;}

    int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            if(isSorted(nums[start],nums[end]))
                return nums[start];
            
            int mid=findMid(start,end);
            bool leftSorted=isSorted(nums[start],nums[mid]);

            if(leftSorted)     start=mid+1;
            else    end=mid;
        }
        return -1;
    }
};