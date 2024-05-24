class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,1);
        sort(nums.begin(),nums.end());
        int maxi=0,lastindex=0;
        prev[0]=0;
        for(int i=1;i<n;i++)
        {
            prev[i]=i;
            for(int j=0;j<i;j++)
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }

            if(dp[i]>maxi)
            {
                lastindex=i;
                maxi=dp[i];
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(prev[lastindex]!=lastindex)
            ans.push_back(nums[lastindex=prev[lastindex]]);
            
        reverse(ans.begin(),ans.end());
        return ans;
    }
};