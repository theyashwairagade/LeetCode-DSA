class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans= 0;
        for(auto &i: nums)
            if(i%3)
                ans++;
        return ans;
    }
};