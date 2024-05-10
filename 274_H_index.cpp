class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int i, n=citations.size();
        for(i=1;i<=n;i++)
            if(citations[n-i]<i)    break;
        return i-1;
    }
};