class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bin;
        unsigned int ans=0;
        unsigned int multiplier=2147483648;
        while(n)
        {
            bin+=to_string(n%2);
            n/=2;
        }
        for(int i=0;i<bin.size();i++)
        {
            ans+=((int(bin[i])-int('0'))*multiplier);
            multiplier/=2;
        }
        return ans;
    }
};


// Optimized
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=0;i<32;i++)
        {
            ans<<=1;
            ans+=(n&1);
            n>>=1;
        }
        return ans;
    }
};



// Bitmask approach
// Favorite
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xffff0000) >>16) | ((n & 0x0000ffff) <<16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};