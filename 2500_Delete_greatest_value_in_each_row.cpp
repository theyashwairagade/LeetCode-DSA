class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(vector<int>&a:grid) sort(a.begin(),a.end());
        int size=grid[0].size(),ans=0;
        for(int i=0;i<size;i++)
        {
            int max=0;
            for(int j=0;j<grid.size();j++)  if(grid[j][i]>max)  max=grid[j][i];
            ans+=max;
        }
        return ans;
    }
};