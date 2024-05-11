class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int &n, int &m, int i, int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X' || visited [i][j])
            return ;
        visited[i][j]=true;
        dfs(board, visited, n, m, i-1, j);
        dfs(board, visited, n, m, i, j-1);
        dfs(board, visited, n, m, i+1, j);
        dfs(board, visited, n, m, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        // Left and right boundary
        for(int i=0; i<n; i++)
            dfs(board, visited, n, m, i, 0),
            dfs(board, visited, n, m, i, m-1);
        
        // Top and bottom boundary
        for(int i=0; i<m; i++)
            dfs(board, visited, n, m, 0, i),
            dfs(board, visited, n, m, n-1, i);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(visited[i][j])
                    board[i][j]='O';
                else
                    board[i][j]='X';
        return;
    }
};