// Brutte Force with time complexity of O(n)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])
            return k;
        for(const auto &i: arr)
            if(i<=k)
                k++;
            else    return k;
        return k;
    }
};





// Optimal with time complexity of O(logn)
class Solution {
public:
    int missing(vector<int> &arr, int &i)
        {return arr[i]-i-1;}
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}

    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])
            return k;

        int start=0, end=arr.size()-1;
        while(start<=end)
        {
            int mid=findMid(start,end);
            if(missing(arr,mid)<k)
                start=mid+1;
            else
                end=mid-1;
        }
        return arr[end]-missing(arr,end)+k;
    }
};