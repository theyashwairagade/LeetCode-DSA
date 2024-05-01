// Time complexity of O(n) won't run due to time limit exceeded
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if(x==1.00000 || x==0.00000)    return x;
        if(n>=0)
            while(n--)
                ans*=x;
        else
            while(n++)
                ans/=x;
        return ans;
    }
};


class Solution {
public:
    double myPow(double x, int n) {
        if(n==(-2147483648))    return (1*myPow(x,n+1))/x;
        if(n<0) return 1/myPow(x,-n);

        if(n==0)    return 1;
        if(n==1)    return x;

        double half=myPow(x,n/2);
        if(n%2==0)  return half*half;
        else    return x*half*half;
    }
};