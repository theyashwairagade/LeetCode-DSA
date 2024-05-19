class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) 
        {
            bool a = nums[i-1]%2;
            bool b = nums[i]%2;
            if ((a && b) || (!a && !b))
                return false;
        }
        return true;
    }
};
