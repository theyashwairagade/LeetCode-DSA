class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int halfN = n/2;
        int halfM = m/2;

        int ans = 0;
        for(int i=0; i<halfN; i++)
            for(int j=0; j<halfM; j++){
                int count1 = 0;
                if(grid[i][j])
                    count1++;
                
                if(grid[i][m-1-j])
                    count1++;

                if(grid[n-1-i][j])
                    count1++;

                if(grid[n-1-i][m-1-j])
                    count1++;

                if(count1 == 1 || count1 == 3)
                    ans+= 1;
                
                if(count1 == 2)
                    ans+= 2;
            }
        
        if(n%2==0 && m%2==0)
            return ans;
        if(n%2==1 && m%2==1 && grid[halfN][halfM])
            ans++;
        
        int fixed0 = 0, fixed1 = 0, change = 0;
        if(m%2){
            for(int i=0; i<halfN; i++)
                if(grid[i][halfM]!=grid[n-i-1][halfM])
                    change++;
                else if(grid[i][halfM])
                    fixed1++;
                else
                    fixed0++;
        }

        if(n%2){
            for(int j = 0; j<halfM; j++)
                if(grid[halfN][j]!=grid[halfN][m-1-j])
                    change++;
                else if(grid[halfN][j])
                    fixed1++;
                else
                    fixed0++;
        }

        ans+= change;
        if(fixed1%2==1 && change==0)
            ans+=2;

        return ans;
    }
};