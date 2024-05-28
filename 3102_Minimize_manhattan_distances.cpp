class Solution {
public:
    vector<int> maxdist(vector<vector<int>>& points,int excludeid){
        vector<int> res = {-1,-1,-1};
        pair<int,int> minsum = {-1,INT_MAX},maxsum = {-1,INT_MIN}, mindiff = {-1,INT_MAX}, maxdiff = {-1,INT_MIN};
        for(int i=0;i<points.size();i++){
            if(i==excludeid) continue;
            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];

            if(sum<minsum.second) minsum = {i,sum};
            if(sum>maxsum.second) maxsum = {i,sum};
            if(diff<mindiff.second) mindiff = {i,diff};
            if(diff>maxdiff.second) maxdiff = {i,diff};

        }
        if((maxsum.second - minsum.second)>(maxdiff.second-mindiff.second)){
            res[0] = maxsum.second - minsum.second;
            res[1] = minsum.first; res[2] = maxsum.first;

        }
        else{
            res[0] = maxdiff.second-mindiff.second;
            res[1] = mindiff.first; res[2] = maxdiff.first;
        }
        return res;
    }
    int minimumDistance(vector<vector<int>>& points) {
        auto v = maxdist(points,-1);
        int i = v[1],j=v[2];
        return min(maxdist(points,i)[0],maxdist(points,j)[0]);
    }
};