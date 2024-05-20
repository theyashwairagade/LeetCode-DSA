// Extreme brutte force along with memorization 
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // Combine the hash values
    }
};

class Solution {
public:
    int findPaths(unordered_map<pair<int, int>, int, pair_hash> &dp, int m, int n) {
        if (n > m)
            swap(n, m);
        if (m < 0)
            return 0;
        if (m + n == 0)
            return 1;
        if (m + n == 1)
            return 1;
        
        auto it = dp.find({m, n});
        if (it != dp.end())
            return it->second;

        if (n == 0)
            return dp[{m, n}] = findPaths(dp, m - 1, n);
        return dp[{m, n}] = findPaths(dp, m - 1, n) + findPaths(dp, m, n - 1);
    }

    int uniquePaths(int m, int n) {
        unordered_map<pair<int, int>, int, pair_hash> dp;
        return findPaths(dp, m - 1, n - 1);
    }
};





// Simplified the code along with simplifying base condition
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};
class Solution {
    unordered_map<pair<int, int>, int, pair_hash> dp;
public:
    int uniquePaths(int m, int n) {
        if(n>m)
            swap(n,m);
        if (m == 1 && n == 1)
            return 1;
        if(m<=0 || n<=0)
            return 0;
        
        auto it = dp.find({m, n});
        if (it != dp.end())
            return it->second;
        
        return dp[{m, n}] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};





// Reduce stack space by performing tabulation i.e. Bottom Up approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if(i || j)
                {
                    if (i > 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
                else
                    dp[i][j] = 1;
        return dp[m - 1][n - 1];
    }
};





// Performing space optimization from O(m*n) to O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for (int i = 0; i < m; ++i) 
        {
            vector<int> current(n,0);
            for (int j = 0; j < n; ++j) 
                if(i || j)
                {
                    if (i > 0)
                        current[j] += prev[j];
                    if (j > 0)
                        current[j] += current[j - 1];
                }
                else
                    current[j] = 1;
            prev=current;
        }
        return prev[n - 1];
    }
};





// Optimizing time complexity from O(n*m) to min of O(n) and O(m) with space complexity of O(1) due to combinatorics
class Solution {
public:
    int combination(int total, int wanted) 
    {
        if (wanted > total - wanted)
            wanted = total - wanted; // C(n, k) = C(n, n - k)

        long long ans = 1;
        for (int i = 1; i <= wanted; ++i)
            ans = ans * (total - i + 1) / i;
        
        return ans;
    }
    int uniquePaths(int m, int n) {
        return combination(m+n-2,n-1);
    }
};