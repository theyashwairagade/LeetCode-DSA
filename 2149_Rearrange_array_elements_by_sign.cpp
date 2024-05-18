class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int length=nums.size();
        vector<int> ans(length);
        int even=0, odd=1;
        for(int number: nums)
            if(number>0)    ans[even]=number, even+=2;
            else    ans[odd]=number,odd+=2;
        return ans;
    }
};