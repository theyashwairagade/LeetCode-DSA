class Solution {
private:
    void dfs(vector<vector<int>> &grid, int &n, int &m, int i, int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
            return;
        grid[i][j]=2;
        dfs(grid, n, m, i-1, j);
        dfs(grid, n, m, i, j-1);
        dfs(grid, n, m, i+1, j);
        dfs(grid, n, m, i, j+1);
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        // left and right boundary
        for(int i=0; i<n; i++)
            dfs(grid, n, m, i, 0),
            dfs(grid, n, m, i, m-1);
        // top and bottom boundary
        for(int i=0; i<m; i++)
            dfs(grid, n, m, 0, i),
            dfs(grid, n, m, n-1, i);
        
        int ans=0;
        for(auto &vec: grid)
            for(int &i: vec)
                if(i==1)
                    ans++;
        return ans;
    }
};