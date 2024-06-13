class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        unordered_map<int,int> noOfOnesInRow, noOfOnesInCol;
        int n=grid.size(), m=grid[0].size();

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j])
                    noOfOnesInRow[i]++,
                    noOfOnesInCol[j]++;
        
        long long ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j])
                    ans+= ((noOfOnesInRow[i]-1) * (noOfOnesInCol[j]-1)) ;
        return ans;
    }
};