class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        bool odd=n%2;
        long long int ans=0;
        int n2=n/2;
        if(nums[n2]==k) return 0;
        if(nums[n2]>k)
            for(int i=0;i<=n2;i++)
            {
                if(nums[i]>k)   ans+=(nums[i]-k);
            }
        else
            for(int i=n2;i<n;i++)
                if(nums[i]<k)   ans+=(k-nums[i]);
        return ans;
    }
};