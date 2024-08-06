class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int halfN = n/2;
        int halfM = m/2;

        // Checking to make all rows palindromic
        int forRow = 0;
        for(auto &vec: grid){
            for(int i = 0; i<halfM; i++)
                if(vec[i]!=vec[m-1-i])
                    forRow ++;
        }

        // Checking to make all cols palindromic
        int forCol = 0;
        for(int i = 0; i<m; i++)
            for(int j = 0; j<halfN; j++)
                if(grid[j][i]!=grid[n-1-j][i])
                    forCol++;
        
        // cout<<"Row= "<<forRow<<" Col= "<<forCol;
        return min(forRow, forCol);
    }
};