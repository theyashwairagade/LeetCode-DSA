// Using binary Search approach in iterative way time complexity O(logn) and space complexity of O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long unsigned int start=0,mid=x/2;
        int end=x;
        while(start<end && mid<=end)
        {
            if(mid==end-1 && start==mid)    return mid;
            mid=start+(end-start)/2;
            if(mid*mid<x)  start=mid;
            else if(mid*mid>x)  end=mid;
            else if(mid*mid==x)  return mid;
        }
        return end;
    }
};