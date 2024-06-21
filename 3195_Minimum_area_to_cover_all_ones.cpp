class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int startX = INT_MAX, startY= INT_MAX, endX=-1, endY=-1;

        for(int i=0; i<n ;i++)
            for(int j=0; j<m; j++)
                if(grid[i][j])
                    startX=min(startX,i),
                    startY=min(startY,j),
                    endX= max(endX,i),
                    endY=max(endY,j);
        return (endX-startX+1)*(endY-startY+1);
    }
};