class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();

        for(int i=1; i<n; i++)
            for(int j=0; j<m; j++)
                grid[i][j]+=grid[i-1][j];
        
        int ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(j)
                    grid[i][j]+=grid[i][j-1];
                if(grid[i][j]<=k)
                    ans++;
            }
        return ans;
    }
};