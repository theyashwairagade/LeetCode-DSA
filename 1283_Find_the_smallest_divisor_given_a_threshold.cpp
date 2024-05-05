class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool possible(vector<int> &nums, int &threshold, int &divisor)
    {
        int ans=0;
        for(const auto &num: nums)
            ans+=ceil(static_cast<double>(num)/divisor);
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1, end=nums[0];
        for(const auto &num: nums)
            end=max(end,num);
        
        while(start<end)
        {
            int mid=findMid(start,end);
            if(possible(nums, threshold, mid))
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};