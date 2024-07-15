class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int storingX = 0, storingY = 1;

        vector<vector<vector<int>>> prefix(n, vector<vector<int>> (m, vector<int> (2, 0)));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(j)
                    prefix[i][j][storingX]=prefix[i][j-1][storingX],
                    prefix[i][j][storingY]=prefix[i][j-1][storingY];
                
                if(grid[i][j]=='X')
                    prefix[i][j][storingX]++;
                if(grid[i][j]=='Y')
                    prefix[i][j][storingY]++;
            }
        
        int ans = 0;
        for(int j=0; j<m; j++){
            int countX = 0, countY = 0;
            for(int i=0; i<n; i++){
                countX += prefix[i][j][storingX],
                countY += prefix[i][j][storingY];

                if(countX && countX==countY)
                    ans++;
            }
        }
        return ans;
    }
};