class Solution {
public:
    unordered_map<int, int> mapping;

    int numSquares(int n) {
        if (n == 0 || n == 1)
            return n;

        auto it = mapping.find(n);
        if (it != mapping.end())
            return it->second;

        int minCount = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + numSquares(n - i * i);
            minCount = min(result, minCount);
        }

        mapping[n] = minCount;
        return minCount;
    }
};