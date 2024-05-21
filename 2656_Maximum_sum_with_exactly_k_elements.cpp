class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        return (k*(2*(*max_element(nums.begin(), nums.end()))+k-1))/2;
    }
};