class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0)    return true;
        long n=0,old=x;
        while(old)
        {
            n*=10;
            n+=(old%10);
            old/=10;
        }
        if(n==x)  return true;
        else return false;
    }
};