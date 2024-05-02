// Solution of Search in Rotated Sorted Array I fails in condition,
//  when nums[start]=nums[mid]=nums[end]
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool isSorted(int &start, int &end)
        {return end>=start;}
    bool inRange(int &start, int &end, int &target)
        {return start<=target && target<=end;}
    bool equal(int &a, int &b, int &c)
        {return a==b && a==c;}

    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=findMid(start,end);
            if(nums[mid]==target)   return true;

            // So added this block of code to handle that condition
            if(equal(nums[start],nums[mid],nums[end]))
            {
                start++;
                end--;
                continue;
            }
            
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
        return false;
    }
};