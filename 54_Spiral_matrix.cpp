class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();
        // Remember logic for looops
        int loops = min((rows + 1) / 2, (cols + 1) / 2);
        for (int loop = 0; loop < loops; loop++) 
        {
            for (int i = loop; i < cols - loop; i++) 
                ans.push_back(matrix[loop][i]);
            for (int i = loop + 1; i < rows - loop; i++) 
                ans.push_back(matrix[i][cols - 1 - loop]);
            // Remember if condition
            if (rows - 1 - loop != loop) 
                for (int i = cols - 2 - loop; i >= loop; i--) 
                    ans.push_back(matrix[rows - 1 - loop][i]);
            // Remember if condition
            if (cols - 1 - loop!= loop) 
                for (int i = rows - 2 - loop; i > loop; i--) 
                    ans.push_back(matrix[i][loop]);
        }
        return ans;
    }
};