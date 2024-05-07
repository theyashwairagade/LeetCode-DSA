// Brutte Force
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n)
        {
            if(n%2)    ans++;
            n/=2;
        }
        return ans;
    }
};


// Optimized code
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n)
            n&=(n-1),
            ans++;
        return ans;
    }
};