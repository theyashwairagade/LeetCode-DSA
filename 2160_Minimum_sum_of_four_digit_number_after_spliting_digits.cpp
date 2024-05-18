class Solution {
public:
    int minimumSum(int num) {
        int temp=num;
        int m1=INT_MAX,m2=INT_MAX;
        while(temp)
        {
            int t=temp%10;
            if(m1>t)
            {
                m2=m1;
                m1=t;
            }
            else if(m2>t)   m2=t;
            temp/=10;
        }
        temp=m1+m2;
        while(num)
        {
            int t=num%10;
            if(m1<t)
            {
                m2=m1;
                m1=t;
            }
            else if(m2<t)   m2=t;
            num/=10;
        }
        temp*=10;
        temp+=(m1+m2);
        return temp;
    }
};