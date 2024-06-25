// class Solution {
// public:
//     int maximumLength(vector<int>& nums, int k) {
//         vector<vector<int>> dp(k, vector<int>(k,0));
//         int ans = 0;
//         for(auto &num: nums)
//         {
//             int currMod = num%k;
//             for(int prevMod = 0; prevMod < k; prevMod++)
//             {
//                 dp[currMod][prevMod] = max(dp[currMod][prevMod], 1+dp[prevMod][currMod]);
//                 ans = max(ans, dp[currMod][prevMod]);
//             }
//         }
//         return ans;
//     }
// };





// Space optimization from O(k square) to O(k)
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for(int mod= 0; mod<k; mod++)
        {
            vector<int> dp(k, 0);
            for(auto &num: nums)
            {
                int currRem = num%k;
                int prevRem = (mod-currRem + k)%k;
                dp[currRem]=max(dp[currRem], 1+dp[prevRem]);
                ans = max(ans, dp[currRem]);
            }
        }
        return ans;
    }
};