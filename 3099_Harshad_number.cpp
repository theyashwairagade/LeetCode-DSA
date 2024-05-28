class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0,temp=x;
        while(temp)
        {
            sum+=temp%10;
            temp/=10;
        }
        if(x%sum)   return -1;
        return sum;
    }
};