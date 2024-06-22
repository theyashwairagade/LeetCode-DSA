class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        int left=0, right =0, ans = 1;
        k*=2;
        while(right<n){
            while(nums[right]-nums[left]>k)
                left++;
            if(nums[right]-nums[left]<=k)
                ans=max(ans, ++right-left);
        }
        return ans;
    }
};