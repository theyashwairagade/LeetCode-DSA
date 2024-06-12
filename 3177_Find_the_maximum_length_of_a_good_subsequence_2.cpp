// This will give tle as has time complexity of O(n square k)
// class Solution {
//     int solve(vector<vector<int>> &dp, vector<int> &nums, int k,int index)
//     {
//         if(k<0)
//             return -1;
//         if(dp[k][index]!=-1)
//             return dp[k][index];
//         int ans=0;
//         for(int i=0; i<index; i++)
//             if(nums[i]==nums[index])
//                 ans=max(ans, 1+solve(dp, nums,k,i));
//             else
//                 ans=max(ans, 1+ solve(dp, nums, k-1, i));
//         return dp[k][index]= ans;
//     }
// public:
//     int maximumLength(vector<int>& nums, int k) {
//         int n=nums.size();
//         int ans=1;
//         vector<vector<int>> dp(51, vector<int> (n,-1));
//         for(int i=1; i<n; i++)
//             ans=max(ans,1+solve(dp,nums, k ,n-i));
//         return ans;
//     }
// };





// Optimizing it further
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,unordered_map<int,int>> dp;   // nums[i],k
        vector<int> dpForK(k+1, 0);
        for(int i=0; i<n; i++)
            for(int j=k; j>=0; j--)
            {
                dp[nums[i]][j]++;
                if(j)
                    dp[nums[i]][j]=max(dp[nums[i]][j], dpForK[j-1]+1);
                dpForK[j]=max(dpForK[j], dp[nums[i]][j]);
            }        
        // for(auto &pr1: dp)
        // {
        //     cout<<"For "<<pr1.first<<": ";
        //     for(auto &pr2: pr1.second)
        //         cout<<"("<<pr2.first<<","<<pr2.second<<") ";
        //     cout<<endl;
        // }
        int ans=0; 
        // cout<<"dpForK: ";
        for(int i=0; i<=k; i++)
            // cout<<"("<<i<<","<<dpForK[i]<<") ",
            ans=max(ans, dpForK[i]);
        return ans;
    }
};