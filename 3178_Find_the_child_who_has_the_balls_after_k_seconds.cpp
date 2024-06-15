class Solution {
public:
    int numberOfChild(int n, int k) {
        k%=(2*(n-1));
        if(k<n)
            return k;
        int multiplier = k - n + 1;
        multiplier *= 2;
        return k-multiplier;
    }
};