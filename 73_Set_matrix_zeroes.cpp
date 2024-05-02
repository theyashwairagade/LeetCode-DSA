// Brutte force with time complexity of O(m*n) and space complexity of o(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0) zeros.push_back({i,j});
        for(auto pr:zeros)
        {
            for(int i=0;i<n;i++)
                matrix[pr.first][i]=0;
            for(int i=0;i<m;i++)
                matrix[i][pr.second]=0;
        }
    }
};


// More optimized with time complexity of O(n*m) and space complexity of O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<bool> rows(m),cols(n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0) cols[j]=rows[i]=true;
        for(int i=0;i<n;i++)
            if(cols[i]==true)
                for(int j=0;j<m;j++)
                    matrix[j][i]=0;
        for(int i=0;i<m;i++)
            if(rows[i]==true)
                for(int j=0;j<n;j++)
                    matrix[i][j]=0;
    }
};


// More optimized solution with time complexity of O(n*m) with space complexity of O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = false;
        for (int i = 0; i < m; i++) 
        {
            if (matrix[i][0] == 0)  col0 = true;
            for (int j = 1; j < n; j++) 
                if (matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) 
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (matrix[0][0] == 0) 
            for (int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        if (col0) 
            for (int i = 0; i < m; i++) 
                matrix[i][0] = 0;
    }
};
