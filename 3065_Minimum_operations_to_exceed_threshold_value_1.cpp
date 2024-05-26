class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int number: nums)   if(number<k)    ans++;
        return ans;
    }
};