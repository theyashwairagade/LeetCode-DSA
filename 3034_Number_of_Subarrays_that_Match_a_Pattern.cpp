class Solution {
    bool valid(int i, vector<int> &nums, vector<vector<int>> &patternStore){
        for(auto &k: patternStore[0])
            if(nums[i+k+1]>= nums[i+k])
                return false;
        for(auto &k: patternStore[1])
            if(nums[i+k+1]!= nums[i+k])
                return false;
        for(auto &k: patternStore[2])
            if(nums[i+k+1] <= nums[i+k])
                return false;
        return true;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<vector<int>> patternStore(3);

        for(int i=0; i<m; i++)
            patternStore[pattern[i]+1].push_back(i);
        
        int ans = 0;
        for(int i=0; i<n-m; i++)
            if(valid(i, nums, patternStore))
                ans++;
        return ans;
    }
};