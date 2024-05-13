class Solution {
public:
    int fib(int n) {
        if(n<1)     return 0;
        if(n<3)     return 1;
        int a=1,b=1;
        while(n>=3)
        {
            b+=a;
            a=b-a;
            n--;
        }
        return b;
    }
};