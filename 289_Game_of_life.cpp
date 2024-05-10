// Brutte force solution by me with time complexity of O(m*n) and space complexity of O(m*n)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> live;
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++)
        {
            bool rowDec=i>0, rowInc=i+1<m;
            for(int j=0;j<n;j++)
            {
                bool colDec=j>0, colInc=j+1<n;
                int count=0;
                if(rowDec)  count+=board[i-1][j];
                if(rowInc)  count+=board[i+1][j];
                if(colDec)  count+=board[i][j-1];
                if(colInc)  count+=board[i][j+1];

                if(rowDec && colDec)    count+=board[i-1][j-1];
                if(rowDec && colInc)    count+=board[i-1][j+1];
                if(rowInc && colDec)    count+=board[i+1][j-1];
                if(rowInc && colInc)    count+=board[i+1][j+1];

                if(((board[i][j]) && (count==2 || count==3)) || (!board[i][j] && count==3))
                    live.push_back({i,j});
            }
        }
        for(auto &vec:board)
            for(auto &num:vec)
                num=0;
        for(auto pr:live)
            board[pr.first][pr.second]=1;
    }
};


// Self optimized with time complexity of O(m*n) with space complexity of O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        unordered_map<int,pair<int,int>> mp;
        mp[0]={0,0}, mp[1]={1,1},mp[2]={0,1}, mp[-2]={1,0};
        // Phle Abhi Denoted
        //   0    0     0
        //   0    1     2
        //   1    0    -2
        //   1    1     1
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++)
        {
            bool rowDec=i>0, rowInc=i+1<m;
            for(int j=0;j<n;j++)
            {
                bool colDec=j>0, colInc=j+1<n;
                int count=0;
                if(rowDec)  count+=mp[board[i-1][j]].first;
                if(rowInc)  count+=mp[board[i+1][j]].first;
                if(colDec)  count+=mp[board[i][j-1]].first;
                if(colInc)  count+=mp[board[i][j+1]].first;

                if(rowDec && colDec)    count+=mp[board[i-1][j-1]].first;
                if(rowDec && colInc)    count+=mp[board[i-1][j+1]].first;
                if(rowInc && colDec)    count+=mp[board[i+1][j-1]].first;
                if(rowInc && colInc)    count+=mp[board[i+1][j+1]].first;

                int temp=board[i][j];
                if(mp[temp].first && (count<2 || count>3))
                    board[i][j]=-2;
                if(!mp[temp].first && count==3)
                    board[i][j]=2; 
            }
        }
        for(auto &vec: board)
            for(auto &num:vec)
                if(num==2)  num=1;
                else if(num==-2)    num=0;
    }
};