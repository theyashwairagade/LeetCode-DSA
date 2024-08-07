class neighborSum {
    vector<int> adj, dig;
    int n;
public:
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        adj.resize(n*n);
        dig.resize(n*n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(j)
                    adj[grid[i][j]]+=grid[i][j-1];
                if(i)
                    adj[grid[i][j]]+=grid[i-1][j];
                if(i+1<n)
                    adj[grid[i][j]]+=grid[i+1][j];
                if(j+1<n)
                    adj[grid[i][j]]+=grid[i][j+1];



                if (i > 0 && j > 0) {
                    dig[grid[i][j]] += grid[i-1][j-1]; // Top-left diagonal
                }
                if (i+1 < n && j > 0) {
                    dig[grid[i][j]] += grid[i+1][j-1]; // Bottom-left diagonal
                }
                if (i > 0 && j+1 < n) {
                    dig[grid[i][j]] += grid[i-1][j+1]; // Top-right diagonal
                }
                if (i+1 < n && j+1 < n) {
                    dig[grid[i][j]] += grid[i+1][j+1]; // Bottom-right diagonal
                }
            }
    }
    
    int adjacentSum(int value) {
        return adj[value];
    }
    
    int diagonalSum(int value) {
        return dig[value];
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */