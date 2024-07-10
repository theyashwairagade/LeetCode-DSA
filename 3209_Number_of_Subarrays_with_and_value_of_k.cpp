class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int, int> prev;
        int n = nums.size();
        long long ans = 0;
        for (int num : nums){
            map<int, int> cur;
            for (auto [andVal, count] : prev)
                cur[andVal & num] += count;
            cur[num]++;

            ans += cur[k];
            prev = cur;
        }
        return ans;
    }
};