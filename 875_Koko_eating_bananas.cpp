class Solution {
public:
    int findMid(int &start, int &end)
        {return start+(end-start)/2;}
    int findHours(vector<int> &piles, int &n) {
        int ans = 0;
        for (const int &pile : piles)
            ans += ceil(static_cast<double>(pile) / n);
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int start=1, end=piles[n-1];

        while(start<end)
        {
            int mid=findMid(start,end);
            int requiredHours=findHours(piles,mid);

            if(requiredHours<=h)
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};