// class Solution {
//     bool isSafe(int row, int col, vector<string> &board, int n){
//         int tempRow, tempCol;
//         // Checking upper diagonal
//         // \
//         //  \
//         //   \
//         //    Q
//         tempRow = row, tempCol = col;
//         while(tempRow >= 0 && tempCol >= 0)
//         {
//             if(board[tempRow][tempCol]=='Q')
//                 return false;
//             tempRow--,
//             tempCol--;
//         }

//         // Checking let side
//         // - - - Q
//         tempCol = col, tempRow = row;
//         while(tempCol >= 0){
//             if(board[tempRow][tempCol]=='Q')
//                 return false;
//             tempCol--;
//         }

//         // checking lower diagonal
//         //    Q
//         //   /
//         //  /
//         // /
//         tempCol = col , tempRow = row;
//         while(tempRow<n && tempCol >=0){
//             if(board[tempRow][tempCol]=='Q')
//                 return false;
//             tempRow++,
//             tempCol--;
//         }
//         return true;
//     }
//     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row = 0; row<n; row++)
//             if(isSafe(row, col, board, n)){
//                 board[row][col]='Q';
//                 solve(col+1, board, ans, n);
//                 board[row][col]='.';
//             }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n,'.'));
//         solve(0, board, ans, n);
//         return ans;
//     }
// };





// Optimizing isSafe function from O(n) to O(1)
class Solution {
    bool isSafe(vector<vector<bool>> &checking, int row, int col, int n){
        // checking left side
        if(checking[0][row])
            return false;
        // checking upper diagonal
        if(checking[1][n-1+col-row])
            return false;
        // checking lower diagonal
        if(checking[2][row+col])
            return false;
        return true;
    }
    void add(vector<vector<bool>> &checking, int row, int col, int n)
        {checking[0][row]= checking[1][n-1+col-row]= checking[2][row+col] = true;}
    void remove(vector<vector<bool>> &checking, int row, int col, int n)
        {checking[0][row]= checking[1][n-1+col-row]= checking[2][row+col] = false;}
    void solve(vector<vector<bool>> &checking, int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++)
            if(isSafe(checking, row, col, n)){
                board[row][col]='Q';
                add(checking, row, col, n);
                solve(checking, col+1, board, ans, n);
                remove(checking, row, col, n);
                board[row][col]='.';
            }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        vector<bool> checkRow(n,false), checkUpperDiag(2*n-1,false), checkLowerDiag(2*n-1,false);
        vector<vector<bool>> checking = {checkRow, checkUpperDiag, checkLowerDiag};
        solve(checking, 0, board, ans, n);
        return ans;
    }
};