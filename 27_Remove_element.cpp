class Solution {
public:
    void swap(int &a, int&b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    int removeElement(vector<int>& nums, int val) {
        if (std::find(nums.begin(), nums.end(), val) == nums.end())
            return nums.size();
        int start=0,end=nums.size()-1;
        while(start<end)
        {
            if(nums[start]==val)
            {
                if(nums[end]!=val)  swap(nums[start],nums[end]);
                else    end--;
            }else   start++;
        }
        return start;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for(int &num:nums)  if(num!=val)    nums[ans++]=num;
        return ans;
    }
};