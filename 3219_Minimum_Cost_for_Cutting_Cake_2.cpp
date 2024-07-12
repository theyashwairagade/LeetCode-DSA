class Solution {
public:
    long long minimumCost(int n, int m, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        
        n-=2, m-=2;

        int hCuts = 1, vCuts = 1;
        long long ans = 0;
        while(n>=0 && m>=0)
            if(horizontalCut[n]>= verticalCut[m])
                ans += horizontalCut[n--]*vCuts,
                hCuts++;
            else
                ans += verticalCut[m--]*hCuts,
                vCuts++;
        
        while(n>=0)
            ans += horizontalCut[n--]*vCuts,
            hCuts++;
        while(m>=0)
            ans += verticalCut[m--]*hCuts,
            vCuts++;
        
        return ans;
    }
};