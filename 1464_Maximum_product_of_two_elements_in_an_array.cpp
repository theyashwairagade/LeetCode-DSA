class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int i=INT_MIN,j=INT_MIN;
        for(int a:arr)
            if(a>i)
            {
                j=i;
                i=a;
            }
            else if(a>j)    j=a;
        return (i-1)*(j-1);
    }
};