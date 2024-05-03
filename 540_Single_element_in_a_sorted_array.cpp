// Over complicated optimized code by me
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool even(int &n)
        {return !(n%2);}
    bool equal(int &a, int &b)
        {return a==b;}
    
    int singleNonDuplicate(vector<int>& nums) {
        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            if(equal(start,end))  return nums[start];

            int mid=findMid(start,end);
            if(even(mid))
                if(equal(nums[mid],nums[mid+1]))
                    start=mid+2;
                else if(equal(start,mid) || !equal(nums[mid-1],nums[mid]))
                    return nums[mid];
                else end=mid-2;
            else
                if(equal(nums[mid],nums[mid+1]))
                    end=mid-1;
                else if(equal(start,mid))
                    return nums[mid];
                else if(equal(nums[mid-1],nums[mid]))
                    start=mid+1;
                else    return nums[mid];
        }
        return -1;
    }
};





// We can simplify this too