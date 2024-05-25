class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();
        for(int j=0;j<column;j++)
        {   bool present=false;
            int maxNumber=matrix[0][j];
            for(int i=0;i<row;i++)
            {   int current=matrix[i][j];
                if(!present && current==-1)    present=true;
                if(maxNumber<current)
                    maxNumber=current;
            }
            if(present)
                for(int i=0;i<row;i++)
                    if(matrix[i][j]==-1)    matrix[i][j]=maxNumber;
        }
        return matrix;
    }
};