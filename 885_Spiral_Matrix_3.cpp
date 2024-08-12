class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        bool coming = true;
        vector<vector<int>> ans;

        for(int cycle = 1; coming; cycle++){
            coming = false;

            // Top
            if(rStart-cycle+1>=0)
                for(int i=max(0, cStart-cycle+1); i<=min(cols-1, cStart+cycle-1); i++)
                    coming = true,
                    ans.push_back({rStart-cycle+1, i});
            
            // Right
            if(cStart+cycle<cols)
                for(int i=max(0, rStart-cycle+1); i<=min(rows-1, rStart+cycle-1); i++)
                    coming = true,
                    ans.push_back({i, cStart+cycle});
            
            // Bottom
            if(rStart+cycle<rows)
                for(int i=min(cols-1, cStart+cycle); i>=max(0, cStart-cycle+1); i--)
                    coming = true, 
                    ans.push_back({rStart+cycle, i});
            
            // Left
            if(cStart-cycle>=0)
                for(int i=min(rows-1, rStart+cycle); i>=max(0, rStart-cycle+1); i--)
                    coming = true,
                    ans.push_back({i, cStart-cycle});
        }
        return ans;
    }
};