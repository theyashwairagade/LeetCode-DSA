class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> increasingDP(n,1);
        vector<int> decreasingDP(n, 1);
        // find LIS
        for(int i=0; i<n; i++)
            for(int prev=0; prev<i; prev++)
                if(nums[i] > nums[prev] && 1+increasingDP[prev] > increasingDP[i] )
                    increasingDP[i] = 1+increasingDP[prev];

        for(int i=n-1; i>=0; i--)
            for(int prev=n-1; prev>i; prev--)
                if(nums[i] > nums[prev] && 1+decreasingDP[prev] > decreasingDP[i])
                    decreasingDP[i] =1+decreasingDP[prev];

        int longest =0;
        for(int i=0; i<n; i++)
            if(decreasingDP[i] >1 and increasingDP[i]>1)
                longest = max(longest,increasingDP[i] + decreasingDP[i]-1);
        
        return n-longest;
    }
};