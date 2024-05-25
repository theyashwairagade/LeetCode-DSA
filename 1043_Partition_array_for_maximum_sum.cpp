// Solving using front partitioning will give tle
// class Solution {
// public:
//     int solve(vector<int> &arr, int &k, int start, int end)
//     {
//         if(start>end)
//             return 0;
//         if(end-start<k)
//         {
//             int maxValue=INT_MIN;
//             for(int i=start; i<=end; i++)
//                 maxValue=max(maxValue,arr[i]);
//             return (end-start+1) * maxValue;
//         }
//         int ans=INT_MIN;
//         for(int i=start; i<start+k; i++)
//         {
//             int sum=solve(arr,k,start,i)+solve(arr,k,i+1,end);
//             ans=max(ans,sum);
//         }
//         return ans;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n=arr.size();
//         return solve(arr, k, 0, n-1);
//     }
// };





// To perform overlapping subproblems in constant time perform memorization
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &arr, int &k, int start, int end)
    {
        if(start>end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];

        if(end-start<k)
        {
            int maxValue=INT_MIN;
            for(int i=start; i<=end; i++)
                maxValue=max(maxValue,arr[i]);
            return dp[start][end]= (end-start+1) * maxValue;
        }
        int ans=INT_MIN;
        for(int i=start; i<start+k; i++)
        {
            int sum=solve(dp, arr,k,start,i)+solve(dp, arr,k,i+1,end);
            ans=max(ans,sum);
        }
        return dp[start][end]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(dp, arr, k, 0, n-1);
    }
};