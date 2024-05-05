class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back(vector<int>{1});
        for(int vec=1;vec<numRows;vec++)
        {
            vector<int> currentRow;
            currentRow.push_back(1);
            int previousRowSize=ans[vec-1].size();

            for(int i=0;i<previousRowSize-1;i++)    
                currentRow.push_back(ans[vec-1][i]+ans[vec-1][i+1]);
            
            currentRow.push_back(1);
            ans.push_back(currentRow);
        }
        return ans;
    }
};