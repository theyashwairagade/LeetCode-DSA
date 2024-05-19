class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> countParity(n, 0);

        // Initialize countParity based on adjacent elements parity
        for (int i = 1; i < n; i++) {
            countParity[i] = countParity[i - 1];
            bool a = nums[i - 1] % 2;
            bool b = nums[i] % 2;
            if ((a && b) || (!a && !b)) {
                countParity[i]++;
            }
        }

        vector<bool> ans;
        for (const auto &query : queries)
            ans.push_back((countParity[query[1]] - countParity[query[0]]) == 0);

        return ans;
    }
};