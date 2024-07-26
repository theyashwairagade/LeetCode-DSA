// Using kadane's algorithm in n square times i.e. time complexity of O(n cube)
class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    void kadanesAlgo(vector<int> &vec, int &n, int &ans, int &k){
        int currentSum = 0;
        set<int> st={0};
        for(auto &i: vec){
            currentSum += i;
            auto it = st.lower_bound(currentSum-k);
            if(it!=st.end())
                ans = max(ans, currentSum - *it);
            st.insert(currentSum);
        }
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int finalK) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int> dp(m, 0);
            for(int j=i; j<n; j++){
                for(int k=0; k<m; k++)
                    dp[k]+=matrix[j][k];
                kadanesAlgo(dp, m, ans, finalK);
                if(ans == finalK)
                    return ans;
            }
        }
        return ans;
    }
};