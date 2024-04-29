// Brutte Force by me
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        int first=grid[0][0];
        if(n==1)    return new Node(first,true);
        for(const auto &row:grid)
            for(const int &val: row)
            {
                if(val!=first)
                {
                    n/=2;
                    vector<vector<int>> tl,tr,bl,br;
                    for(int i=0;i<n;i++)
                    {
                        vector<int> v1,v2,v3,v4;
                        for(int j=0;j<n;j++)
                        {
                            v1.push_back(grid[i][j]);
                            v2.push_back(grid[i][j+n]);
                            v3.push_back(grid[i+n][j]);
                            v4.push_back(grid[i+n][j+n]);
                        }
                        tl.push_back(v1);
                        tr.push_back(v2);
                        bl.push_back(v3);
                        br.push_back(v4);
                    }
                    return new Node(true,false,construct(tl),construct(tr),construct(bl),construct(br));
                }
            }
        return new Node(first,true);
    }
};


// More optimized as don't create the new grid
class Solution {
public:
    bool allValueSame(vector<vector<int>> &grid, int rowIndex, int columnIndex,int n)
    {
        if(n==1)    return true;
        int first=grid[rowIndex][columnIndex];
        for(int i=rowIndex;i<rowIndex+n;i++)
            for(int j=columnIndex;j<columnIndex+n;j++)
                if(grid[i][j]!=first)   return false;
        return true;
    }
    Node* solve(vector<vector<int>> & grid, int rowIndex, int columnIndex, int n)
    {
        if(allValueSame(grid,rowIndex,columnIndex,n))
            return new Node(grid[rowIndex][columnIndex],true);
        n/=2;
        return new Node(
            true,
            false,
            solve(grid,rowIndex,columnIndex,n),
            solve(grid,rowIndex,columnIndex+n,n),
            solve(grid,rowIndex+n,columnIndex,n),
            solve(grid,rowIndex+n,columnIndex+n,n)
        );
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
    }
};