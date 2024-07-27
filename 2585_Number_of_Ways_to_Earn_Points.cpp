class Solution {
    void solve(int target, int index, vector<vector<int>>& types, int &ans, int &mod){
        if(index<0)
            return;
        solve(target, index-1, types, ans, mod);
        // cout<<"Push "<<target<<","<<index<<endl;
        int limit = min(types[index][0], target/types[index][1]);
        for(int i=1; i<=limit; i++){
            target -= types[index][1];
            if(!target){
                ans++;
                ans%=mod;
                // cout<<"increment ans Pop "<<target<<","<<index<<endl;
                return ;
            }
            solve(target, index-1, types, ans, mod);
        }
        // cout<<"Pop "<<target<<","<<index<<endl;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int ans = 0;
        int mod = 1000000007;
        solve(target, n-1, types, ans, mod);
        return ans;
    }
};





// Using comcept of memonization
class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    // If needed to print 2D vector
    void print(vector<vector<int>> &vec){
        for(auto &i: vec)
            print(i);
    }
    int solve(vector<vector<int>> &dp, int target, int index, vector<vector<int>>& types, int &mod){
        if(index<0)
            return 0;
        if(dp[target][index]!=-1)
            return dp[target][index];
        int ans = 0;
        ans += solve(dp, target, index-1, types, mod);
        ans %= mod;

        int limit = min(types[index][0], target/types[index][1]);
        for(int i=1; i<=limit; i++){
            target -= types[index][1];
            if(!target){
                ans++;
                ans%=mod;
                // cout<<"increment ans Pop "<<target<<","<<index<<endl;
                return dp[target][index] = ans;
            }
            ans += solve(dp, target, index-1, types, mod);
            ans %= mod;
        }
        return dp[target][index] = ans;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mod = 1000000007;
        vector<vector<int>> dp(target+1, vector<int> (n, -1));
        int ans =  solve(dp, target, n-1, types, mod) % mod;
        print(dp);
        return ans;
    }
};