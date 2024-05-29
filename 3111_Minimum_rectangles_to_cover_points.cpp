class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int start=points[0][0], ans=1;
        for(const auto &vec: points)
            if(start+w<vec[0])
                ans++,start=vec[0];
        return ans;
    }
};