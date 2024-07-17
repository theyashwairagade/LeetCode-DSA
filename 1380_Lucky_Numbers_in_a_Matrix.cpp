class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> eachRow(n, INT_MAX), eachCol(m, INT_MIN);

        for(int i=0; i<n; i++)
            for(int j = 0; j<m; j++)
                eachRow[i] = min(eachRow[i], matrix[i][j]),
                eachCol[j] = max(eachCol[j], matrix[i][j]);
        
        vector<int> ans;
        for(int i=0; i<n; i++)
            for(int j= 0; j<m; j++)
                if(eachRow[i] == eachCol[j] && eachRow[i] == matrix[i][j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};