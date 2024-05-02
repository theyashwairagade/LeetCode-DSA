class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length=nums.size();
        if(length<2)    return length;
        int ans=2;
        for(int i=2;i<length;i++)
            if(nums[i]!=nums[ans-2])    nums[ans++]=nums[i];
        return ans;
    }
};