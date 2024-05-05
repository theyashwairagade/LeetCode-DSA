// Did with help of gpt
class Solution {
public:
    int findMax(vector<int> &arr) {
        int ans = arr[0];
        for (const int &n : arr)
            ans = max(ans, n);
        return ans;
    }
    int findMid(int &start, int &end) {
        return start + (end - start) / 2;
    }
    int findBouquets(vector<int> &nums, int &k, int &time) {
        int ans = 0, n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= time) {
                count++;
                if (count == k) {
                    ans++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n)   return -1;

        int start = 1, end = findMax(bloomDay);
        int ans = end;
        while (start <= end) {
            int mid = findMid(start, end);
            if (findBouquets(bloomDay, k, mid) >= m) {
                ans = mid; // Update ans
                end = mid - 1; // Explore lower values
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
