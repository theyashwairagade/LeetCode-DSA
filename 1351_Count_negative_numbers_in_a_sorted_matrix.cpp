class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(vector<int>&a: grid)
            for(int j=a.size()-1;j>=0 && a[j]<0;j--) 
                ans++;
        return ans;
    }
};