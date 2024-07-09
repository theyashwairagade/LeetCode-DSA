class Solution {
    void add(vector<int> &a, vector<int> &b, unordered_map<double, int> &mp) {
        int dx = b[0] - a[0];
        int dy = b[1] - a[1];
        if(!dx && !dy)
            return;
        
        double slope = dx ? (double) dy / dx : numeric_limits<double>::infinity();
        if(mp[slope])
            mp[slope]++;
        else
            mp[slope]=2;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n==1)
            return 1;

        int ans = 0;
        for(auto &pointA: points){
            unordered_map<double, int> mp;
            for(auto &pointB: points)
                add(pointA, pointB, mp);
            for(auto &pr: mp)
                ans = max(ans, pr.second);
        }
        return ans;
    }
};