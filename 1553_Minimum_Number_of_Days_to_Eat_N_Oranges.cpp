// Getting Stack overflow
class Solution {
    int solve(vector<int> &dp, int n){
        if(dp[n]!=-1)
            return dp[n];
        int minus = INT_MAX, by2 = INT_MAX, by3 = INT_MAX;
        minus = solve(dp, n-1);
        if(n%2 == 0)
            by2 = solve(dp, n/2);
        if(n%3 == 0)
            by3 = solve(dp, n/3);
        return dp[n] = 1 + min(minus, min(by2, by3));
    }
public:
    int minDays(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        return solve(dp, n);
    }
};





// So optimizing by reducing stack space by building iterative approach
// But still giving tle as O(n) don't work up
class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            int by1 = dp[i-1], by2 = INT_MAX, by3 = INT_MAX;
            if(i%2 == 0)
                by2 = dp[i/2];
            if(i%3 == 0)
                by3 = dp[i/3];
            dp[i] = 1 + min(by1, min(by2, by3));
        }
        return dp[n];
    }
};





// Optimizing using BFS
class Solution {
public:
    int minDays(int n) {
        if(n==1)
            return 1;
        queue<int> q;
        q.push(n);
        q.push(-1);
        int count = 0;

        unordered_set<int> visited;
        while(true){
            if(q.front()==-1){
                q.pop();
                q.push(-1);
                count++;
                continue;
            }
            int tp = q.front();
            q.pop();

            if(tp==2 || tp==3)
                return count+2;

            if(visited.find(tp-1)==visited.end())
                q.push(tp-1),
                visited.insert(tp-1);
            if(tp%2==0 && visited.find(tp/2)==visited.end())
                q.push(tp/2),
                visited.insert(tp/2);
            if(tp%3==0 && visited.find(tp/3)==visited.end())
                q.push(tp/3),
                visited.insert(tp/3);
        }
        return -1;
    }
};





// Optimized soln
class Solution {
    unordered_map<int, int> dp;
public:
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (dp.count(n) == 0)
            dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
};