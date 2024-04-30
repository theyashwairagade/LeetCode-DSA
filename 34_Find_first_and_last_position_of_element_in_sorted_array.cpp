// Brutte Force by me
class Solution {
public:
    int first(vector<int> &nums, int &target)
    {
        int start=0, end=nums.size()-1, ans;
        bool found=false;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<=nums[mid])
            {
                if(nums[mid]==target)
                {
                    found=true;
                    ans=mid;
                }
                end=mid-1;
            }
            else    start=mid+1;
        }
        if(found)   return ans;
        return -1;
    }
    int last(vector<int> &nums, int &target)
    {
        int start=0, end=nums.size()-1, ans;
        bool found=false;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<=target)
            {
                if(nums[mid]==target)
                {
                    found=true;
                    ans=mid;
                }
                start=mid+1;
            }
            else    end=mid-1;
        }
        if(found)   return ans;
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
    }
};



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<=nums[mid])
            {
                if(nums[mid]==target)   ans[0]=mid;
                end=mid-1;
            }
            else    start=mid+1;
        }
        if(ans[0]==-1)  return ans;

        start=ans[0], end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<=target)
            {
                if(nums[mid]==target)   ans[1]=mid;
                start=mid+1;
            }
            else    end=mid-1;
        }
        return ans;
    }
};