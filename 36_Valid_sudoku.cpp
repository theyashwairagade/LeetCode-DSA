class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Checking for rows
        for(int i=0;i<9;i++)
        {
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++)
            {
                char c=board[i][j];
                if(c=='.')    continue;
                mp[c]++;
                if(mp[c]>1)   return false;
            }
        }
        cout<<"Passed rows"<<endl;
        // Checking for columns
        for(int i=0;i<9;i++)
        {
            unordered_map<char,int>mp;
            for(int j=0;j<9;j++)
            {
                char c=board[j][i];
                if(c=='.')    continue;
                mp[c]++;
                if(mp[c]>1)   return false;
            }
        }
        cout<<"Passed cols"<<endl;
        // Check for sub-boxes
        for(int i=0;i<9;i+=3)
            for(int j=0;j<9;j+=3)
            {
                unordered_map<char,int>mp;
                for(int row=i;row<i+3;row++)
                    for(int col=j;col<j+3;col++)
                    {
                        char c=board[row][col];
                        if(c=='.')    continue;
                        mp[c]++;
                        if(mp[c]>1)   return false;
                    }
            }
        cout<<"Passed sub-boxes";
        return true;
    }
};