// Brutte Force time complexity of O(m*n)
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





// Binary Search with time complexity of O(log(m*n))
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int start=0, end= m-1;
        while(start<end)
        {
            int mid=findMid(start,end);
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]>target)
                end=mid-1;
            else if(start==mid)
            {
                if(matrix[mid+1][0]==target)
                    return true;
                if(matrix[mid+1][0]<target)
                    start=mid+1;
                else
                    end=mid;
            }
            else
                start=mid;
        }
        int row=start;
        start=0, end=n-1;
        while(start<end)
        {
            int mid=findMid(start,end);
            if(matrix[row][mid]==target)
                return true;
            if(matrix[row][mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return matrix[row][start]==target;
    }
};





// Flattering to 1D array then binary Search with time complexity of O(log(m*n))
class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int start=0, end= m*n-1;
        while(start<=end)
        {
            int mid=findMid(start,end);
            int key=matrix[mid/n][mid%n];
            if(key==target)
                return true;
            if(key<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return false;
    }
};