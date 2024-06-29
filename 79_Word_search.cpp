class Solution {
    bool solve(int &row, int &col, int &index, vector<vector<char>> &board, string &word){
        if(index == word.size())
            return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col] != word[index])
            return false;
        
        // Changes before starting checking
        char original = board[row][col];
        board[row][col]=' ';
        index++;

        // Checking left side
        col--;
        if(solve(row, col, index, board, word))
            return true;
        col++;

        // checking top side
        row--;
        if(solve(row, col, index, board, word))
            return true;
        row++;

        // checking right side
        col++;
        if(solve(row, col, index, board, word))
            return true;
        col--;

        // checking bottom side
        row++;
        if(solve(row, col, index, board, word))
            return true;
        row--;
        
        // revert changes after checking
        board[row][col]=original;
        index--;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), index = 0;
        for(int i=0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(solve(i, j, index, board, word))
                    return true;
        return false;
    }
};