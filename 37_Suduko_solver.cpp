// one outstanding logic is used so search outstanding in this soln to get that

class Solution {
    // bool search(vector<vector<char>> &board, int val, int row, int col){
    //     for(int i=row; i<row+3; i++)
    //         for(int j= col; j<col+3; j++)
    //             if(board[i][j]-'0'==val)
    //                 return true;
    //     return false;
    // }
    // bool foundAtSmall(int val, int row, int col, vector<vector<char>> &board){
    //     if(row<3 && col<3)
    //         return search(board, val, 0, 0);
    //     if(row<3 && col<6)
    //         return search(board, val, 0, 3);
    //     if(row<3)
    //         return search(board, val, 0, 6);
    //     if(row < 6 && col<3)
    //         return search(board, val, 3, 0);
    //     if(row < 6 && col< 6)
    //         return search(board, val, 3, 3);
    //     if(row<6)
    //         return search(board, val, 3, 6);
    //     if(col<3)
    //         return search(board, val, 6, 0);
    //     if(col<6)
    //         return search(board, val, 6, 3);
    //     return search(board, val, 6, 6);
    // }
    // bool canPut(int val, int row, int col, vector<vector<char>> &board){
    //     // checking in row
    //     for(int i=0; i<9; i++)
    //         if(board[i][col]-'0' == val)
    //             return false;
        
    //     // checking in col
    //     for(int i=0; i<9; i++)
    //         if(board[row][i]-'0' == val)
    //             return false;
        
    //     if(foundAtSmall(val, row, col, board))
    //         return false;
        
    //     return true;
    // }





    // Optimizing canPut function
    bool canPut(int val, int row, int col, vector<vector<char>> &board){
        for(int i=0; i<9; i++)
        {
            // checking in row
            if(board[i][col]-'0' == val)
                return false;

            // checking in col
            if(board[row][i]-'0' == val)
                return false;

            // to check small 3 * 3 box
            // This logic is outstanding
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]-'0'==val)
                return false;
        }
        return true;
    }
    void put(int val, int row, int col, vector<vector<char>> &board)
        {board[row][col]=val+'0';}
    void remove(int val, int row, int col, vector<vector<char>> &board)
        {board[row][col]='.';}
    bool solve(int row, int col, vector<vector<char>>& board){
        if(row == 9)
        {
            return true;
        }
        if(col == 9)
            return solve(row+1, 0, board);
        if(board[row][col]!='.')
            return solve(row, col+1, board);
        
        bool ansFound = false;
        for(int i=1; i<=9; i++)
            if(canPut(i, row, col, board))
            {
                put(i, row, col, board);
                ansFound = solve(row, col+1, board);
                if(ansFound)
                    return true;
                remove(i,row, col, board);
            }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};