class Solution {
public:
    void bfs(vector<vector<int>>& grid, int &n, int &m, queue<pair<int,int>> &q, int i, int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || grid[i][j]==2)
            return;
        grid[i][j]=2;
        q.push({i,j});
    }
    bool allRottern(vector<vector<int>>& grid)
    {
        for(auto &vec: grid)
            for(int &orange: vec)
                if(orange==1)
                    return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        q.push({-1,-1});
        while(q.size()>1)
        {
            int i=q.front().first, j=q.front().second;
            q.pop();
            if(i==-1 || j==-1)
            {
                q.push({-1,-1});
                ans++;
                continue;
            }
            bfs(grid, n, m, q, i-1, j);
            bfs(grid, n, m, q, i+1, j);
            bfs(grid, n, m, q, i, j-1);
            bfs(grid, n, m, q, i, j+1);
        }
        return allRottern(grid)?ans:-1;
    }
};