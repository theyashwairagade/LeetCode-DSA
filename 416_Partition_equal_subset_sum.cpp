class Solution {
public:
bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0){
        return true;
    }
    if(i==0){
        return k == arr[i];
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    bool noPick = solve(i-1, k, arr, dp);
    bool pick = false;
    if(k>=arr[i]){
        pick = solve(i-1, k-arr[i], arr, dp);

    } 

    return dp[i][k] = (noPick || pick);


}
    bool canPartition(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        if(k%2==1){
            return false;
        }
        int k1 = k/2;
        vector<vector<int>> dp(nums.size(), vector<int>(k1+1, -1));
        return solve(nums.size()-1, k1, nums, dp);

        
    }
};