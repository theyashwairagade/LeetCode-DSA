class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i=0; i+2<n; i++)
            for(int j=0; j+2<m; j++){
                int r1 = grid[i][j]+grid[i][j+1]+grid[i][j+2],
                    r2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2],
                    r3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2],
                    c1 = grid[i][j]+grid[i+1][j]+grid[i+2][j],
                    c2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1],
                    c3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2],
                    d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2],
                    d2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
                bool others = false;
                unordered_set<int> distinct;
                for(int k = i; k<i+3 && !others; k++)
                    for(int l=j; l<j+3 && !others; l++){
                        if(grid[k][l]>9 || grid[k][l]==0)
                            others = true;
                        distinct.insert(grid[k][l]);
                    }
                if(!others && distinct.size()==9 && r1 == r2 && r3 == c1 && c2 == c3 && d1 == d2 && r1 == r3 && c2 == d1 && r1 == c2)
                    ans++;
            }
        return ans;
    }
};