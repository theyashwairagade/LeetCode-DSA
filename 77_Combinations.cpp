class Solution {
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited, int &n, int &k, int index){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=index+1; i<=n; i++)
            if(!visited[i])
            {
                temp.push_back(i);
                visited[i]=true;
                solve(ans, temp, visited, n, k, i);
                visited[i]=false;
                temp.pop_back();
            }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visited(n+1, false);
        vector<int> temp;
        vector<vector<int>> ans;
        solve(ans, temp, visited, n, k, 0);
        return ans;
    }
};