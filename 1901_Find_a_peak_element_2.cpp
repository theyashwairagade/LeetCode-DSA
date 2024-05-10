// Time complexity of O(m+n)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=0;
        while(true)
        {
            int left, right, top, bottom;
            if(!col)    left=-1;
            else        left=matrix[row][col-1];

            if(!row)    top=-1;
            else        top=matrix[row-1][col];

            if(col+1==n)    right=-1;
            else            right=matrix[row][col+1];

            if(row+1==m)    bottom=-1;
            else            bottom=matrix[row+1][col];

            int element=matrix[row][col];
            if(element>left && element>right && element>top && element>bottom)
                return {row,col};
            else if(element<left)
                col--;
            else if(element<right)
                col++;
            else if(element<top)
                row--;
            else
                row++;
        }
        return {-1,-1};
    }
};





// time complexity of O(log(m*n))
class Solution {
public: 
    int findRow(vector<vector<int>> &mat,int col,int m, int n){
        int maxi=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int midcol=low+(high-low)/2;
            int midrow=findRow(mat,midcol,m,n);
            int left=midcol-1>=low?mat[midrow][midcol-1]:-1;
            int right=midcol<high?mat[midrow][midcol+1]:-1;
            if(mat[midrow][midcol]>left && mat[midrow][midcol]>right)
            return {midrow,midcol};
            else if(mat[midrow][midcol]<left)
            high=midcol-1;
            else
            low=midcol+1;
        }
        return {-1,-1};
    }
};