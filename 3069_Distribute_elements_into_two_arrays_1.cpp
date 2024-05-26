class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans={nums[0],nums[1]};
        int length=nums.size();
        int a1Last=1;
        for(int i=2;i<length;i++)
            if(ans[a1Last-1]>ans[ans.size()-1]) ans.insert(ans.begin() + a1Last++, nums[i]);
            else    ans.push_back(nums[i]);
        return ans;
    }
};