class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans=0;
        int notBoundary=0;
        for(int move:nums)
        {
            notBoundary+=move;
            if(!notBoundary)   ans++;
        }
        return ans;
    }
};