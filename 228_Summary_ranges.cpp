class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        if(!n)  return {};
        long left=0, right=0; 
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                if(left==right) ans.push_back(to_string(nums[right])),left++;
                else    ans.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
                right++;
                left=right;
            }
            else    right++;
        }
        if(left==right) ans.push_back(to_string(nums[right]));
        else    ans.push_back(to_string(nums[left])+"->"+to_string(nums[right]));
        return ans;
    }
};