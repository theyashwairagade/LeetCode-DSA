class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=m-2;i>=0;i--)
            for(int j=0;j<n;j++)
            {
                int adding=matrix[i+1][j];
                if(j>0)
                    adding=min(adding,matrix[i+1][j-1]);
                if(j+1<n)
                    adding=min(adding,matrix[i+1][j+1]);
                matrix[i][j]+=adding;
            }
        m=matrix[0][0];
        for(int i=0;i<n;i++)
            m=min(m,matrix[0][i]);
        return m;
    }
};