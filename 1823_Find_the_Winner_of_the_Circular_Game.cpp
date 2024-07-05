// Simulation (Brutte force)
class Solution {
    void skip(queue<int> &q){
        q.push(q.front());
        q.pop();
    }
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++)
            q.push(i);
        int ans = -1;
        while(q.size()){
            int tempK = (k-1)%q.size();
            while(tempK--){
                skip(q);
            }
            ans = q.front();
            q.pop();
        }
        return ans;
    }
};





// Recursive approach
class Solution {
    int solve(int n, int &k){
        if(n==1)
            return 0;
        return (solve(n-1, k) + k) % n;
    }
public:
    int findTheWinner(int n, int k) {
        return solve(n, k) +1;
    }
};





// bottom up approach with space optimization
class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int player_num = 2; player_num <= n; ++player_num) {
            res = (res + k) % player_num;
        }
        return res + 1;
    }
};