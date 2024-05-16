class Solution {
public:
    int m(vector<int> &arr)
    {
        int length=arr.size();
        int Max=arr[0],Min=arr[0];
        for(int number:arr)
        {
            if(number>Max)  Max=number;
            if(number<Min)  Min=number;
        }
        return Max-Min;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int length=arr1.size();
        
        vector<int> case1,case2,case3,case4;
        for(int i=0;i<length;i++)
        {
            int a=arr1[i], b=arr2[i];
            case1.push_back(a+b+i);
            case2.push_back(a+b-i);
            case3.push_back(a-b+i);
            case4.push_back(-a+b+i);
        }
        return max(max(m(case1),m(case2)),max(m(case3),m(case4)));
    }
};