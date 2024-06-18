class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool changed = false;
        int ans = 0;
        for(int &num: nums)
            if((!num && !changed) || (num && changed))
                ans++,
                changed ^= 1;
        return ans;
    }
};