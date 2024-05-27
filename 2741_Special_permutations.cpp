// class Solution {
// public:
//     int mod= 1e9+7;
//     int find_permutations(vector<int> &nums, vector<bool> &visited, int prevIndex, int count)
//     {
//         int n=nums.size();
//         if(count==n)
//             return 1;
        
//         long long ways=0;
//         for(int i=0; i<n; i++)
//         {
//             if(visited[i])
//                 continue;
//             if(
//                 prevIndex!=-1 &&
//                 nums[i] % nums[prevIndex] && 
//                 nums[prevIndex] % nums[i]
//                 )
//                     continue;
                    
//             visited[i]=true;
//             ways+=find_permutations(nums, visited, i, count+1)%mod;
//             visited[i]=false;
//         }
//         return ways;
//     }
//     int specialPerm(vector<int>& nums) {
//         int n=nums.size();
//         vector<bool> visited(n, false);
//         int prevIndex= -1;
//         int count=0;
//         return find_permutations(nums, visited, prevIndex, count);
//     }
// };





// To solve overlapping subproblems using memorization but instead of storing entire visited vector we will bitmask it to integer
class Solution {
public:
    int mod= 1e9+7;
    int find_permutations(vector<vector<int>> &dp, vector<int> &nums, int mask, int prevIndex, int count)
    {
        int n=nums.size();
        if(count==n)
            return 1;
        
        if(dp[prevIndex][mask]!=-1)
            return dp[prevIndex][mask];

        long long ways=0;
        for(int i=0; i<n; i++)
        {
            // if(visited[i])
            if(mask & 1<<i)
                continue;
            if(
                // prevIndex!=-1 &&
                mask &&
                nums[i] % nums[prevIndex] && 
                nums[prevIndex] % nums[i]
                )
                    continue;
                    
            ways+=find_permutations(dp, nums, mask | 1<<i, i, count+1)%mod;
        }
        return dp[prevIndex][mask]= ways%mod;
    }
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        int mask=0;
        int prevIndex= 0;
        int count=0;

        vector<vector<int>> dp(n, vector<int> (1<<n, -1));
        return find_permutations(dp, nums, mask, prevIndex, count);
    }
};