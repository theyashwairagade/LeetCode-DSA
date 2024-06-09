class Solution {
    long long area(int len)
        {return len*len;}
    long long area(int blx, int bly, int trx, int tpry) {
        int side = std::min(trx - blx, tpry - bly);
        return static_cast<long long>(side) * side;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long ans=0;

        for(int i=0; i<n; i++)
        {
            int bli1=bottomLeft[i][0], bli2=bottomLeft[i][1];
            int tri1=topRight[i][0], tri2=topRight[i][1];
            for(int j=i+1; j<n; j++)
            {
                int blj1=bottomLeft[j][0], blj2=bottomLeft[j][1];
                int trj1=topRight[j][0], trj2=topRight[j][1];
                bool squareOverlapping=!(tri1 <= blj1 || bli1 >= trj1 || bli2 >= trj2 || tri2 <= blj2);
                if(squareOverlapping)
                    ans=max(ans, area(max(bli1,blj1), max(bli2, blj2), min(tri1, trj1), min(tri2, trj2)));
            }
        }
        return ans;
    }
};