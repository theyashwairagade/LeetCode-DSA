// Brutte Force with time complexity of O(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto &vec: matrix)
            for(const int &num: vec)
                if(num==target)
                    return true;
        return false;
    }
};





// Optimised with time complexity of O(mlog(n))
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool found(const vector<int> &vec, int & target)
    {
        int start=0, end=vec.size()-1;
        while(start<=end)
        {
            int mid=findMid(start,end);
            if(vec[mid]==target)
                return true;
            if(target>vec[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto &vec: matrix)
            if(vec[0]>target)   return false;
            else if(found(vec,target))
                return true;
        return false;
    }
};





// By eliminating either a row or column approach with time complexity of O(n+m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=n-1;
        while(row<m && col>=0)
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                col--;
            else
                row++;
        return false;
    }
};