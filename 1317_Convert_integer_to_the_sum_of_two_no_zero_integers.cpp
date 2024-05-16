class Solution {
public:
    bool nonZero(int n)
    {   while(n)
        {   if(n<10)    return true;
            if(n%10 ==0)    return false;
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int first=n/2;
        int second=n-first;
        cout<<"first "<<first<<" second "<<second<<endl;
        while(!(nonZero(first) && nonZero(second)))
        {   first--;
            second++;
        }
        return vector<int>{first,second};
    }
};