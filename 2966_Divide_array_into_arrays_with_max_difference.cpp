class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int length=nums.size();
        for(int start=0;start<length;start+=3)
        {
            ans.push_back(vector<int>{nums[start],nums[start+1],nums[start+2]});
            if(nums[start+2]-nums[start]>k) return vector<vector<int>>();
        }
        return ans;
    }
};