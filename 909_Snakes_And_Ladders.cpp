// Solving problem of edge case
class Solution {
    int valueOfCell(int cell, int &n, vector<vector<int>> &board){
        int mod = (cell-1) % (2*n);
        int row = n-1-(cell-1)/n, col = mod <n ? mod : 2*n-1-mod;
        int val = board[row][col];
        return (val == -1) ? cell : val;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int destination = n*n;

        queue<int> q;
        vector<bool> alreadyAddedToQueue(n*n+1, false);

        int currentMove = 0;
        q.push(1);
        alreadyAddedToQueue[1]=true;
        q.push(-1);

        while(q.size()>1){
            int currentPosition = q.front();
            q.pop();
            if(currentPosition == destination)
                return currentMove;
            if(currentPosition == -1)
            {
                currentMove++;
                q.push(-1);
                continue;
            }
            for(int nextPosition = currentPosition+1; nextPosition <= currentPosition+6 && nextPosition <= destination; nextPosition++)
                if(!alreadyAddedToQueue[nextPosition])
                {
                    alreadyAddedToQueue[nextPosition]=true;
                    int valOfNextPosition = valueOfCell(nextPosition, n, board);
                    if(valOfNextPosition==destination)
                        return currentMove+1;
                    q.push(valOfNextPosition);
                }
        }
        return -1;
    }
};