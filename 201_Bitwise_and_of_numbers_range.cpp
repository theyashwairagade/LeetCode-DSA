// Brutte force by me won't run due to TLE
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(;left<=right;left++)
            ans^=left;
        return ans;
    }
};


// Optimized
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            count++;
        }
        return left<<count;
    }
};