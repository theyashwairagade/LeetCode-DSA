class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sz=mat.size()-1,ans=0;
        for(int i=0;i<mat.size();i++)
        {
            ans+=mat[i][i];
            if(i!=sz)   ans+=mat[i][sz];
            sz--;
        }
        return ans;
    }
};