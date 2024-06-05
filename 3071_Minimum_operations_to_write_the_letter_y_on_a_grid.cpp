class Solution {
public:
    int maxIndex(vector<int> &arr)
    {
        if(arr[0]>=arr[1] && arr[0]>=arr[2])
            return 0;
        if(arr[1]>=arr[0] && arr[1]>=arr[2])
            return 1;
        return 2;
    }
    int convert(vector<int> &arr, int to)
    {
        int ans=0;
        for(int i=0; i<=2; i++)
            if(i!=to)
                ans+=arr[i];
        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n=grid.size();
        int half= n/2;

        vector<int> belonging(3,0), notBelonging(3,0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                bool leftDigonal=(i==j && i<=half);
                bool rightDigonal=(i+j==n-1 && i<=j);
                bool vertical= (i>=half && j==half);
                if(leftDigonal||rightDigonal||vertical)
                    belonging[grid[i][j]]++;
                else
                    notBelonging[grid[i][j]]++;
            }
        
        int ans=convert(belonging,0)+convert(notBelonging,1);
        for(int i=0; i<=2; i++)
        {
            int temp=convert(belonging,i);
            for(int j=0; j<=2; j++)
                if(j!=i)
                    ans=min(ans, temp+convert(notBelonging,j));
        }
        return ans;
    }
};