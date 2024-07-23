class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long incr = 0, decr = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            long diff = target[i] - nums[i];

            if (diff > 0) {
                if (incr < diff)
                    ans += diff - incr;
                incr = diff;
                decr = 0;
            } else if (diff < 0) {
                if (diff < decr)
                    ans += decr - diff;
                decr = diff;
                incr = 0;
            } else 
                incr = decr = 0;
        }

        return ans;
    }
};