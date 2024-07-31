class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i=1; i<n; i+=2)
            ans+= n-i;
        return ans;
    }
};





// Optimization using concept of AP
class Solution {
    int sumOfAP(int first, int last, int commonDifference) {
        int n = static_cast<int>((last - first) / commonDifference) + 1;
        int sum = (n / 2.0) * (first + last);
        return sum;
    }
public:
    int minOperations(int n) {
        return (n%2) ? sumOfAP(2, n-1, 2) : sumOfAP(1, n-1, 2);
    }
};





// Jugad
class Solution {
public:
    int minOperations(int n) {
        return n*n/4;
    }
};