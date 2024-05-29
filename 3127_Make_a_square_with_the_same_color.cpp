class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int count;
        
        count=0;
        if(grid[0][0]=='B') count++;
        else    count--;
        if(grid[0][1]=='B') count++;
        else    count--;
        if(grid[1][0]=='B') count++;
        else    count--;
        if(grid[1][1]=='B') count++;
        else    count--;
        // cout<<count<<endl;
        if(count==2 || count==-2 || count==4 || count==-4)   return true;
        
        count=0;
        if(grid[0][1]=='B') count++;
        else    count--;
        if(grid[0][2]=='B') count++;
        else    count--;
        if(grid[1][1]=='B') count++;
        else    count--;
        if(grid[1][2]=='B') count++;
        else    count--;
        // cout<<count<<endl;
        if(count==2 || count==-2 || count==4 || count==-4)   return true;
        
        count=0;
        if(grid[1][0]=='B') count++;
        else    count--;
        if(grid[1][1]=='B') count++;
        else    count--;
        if(grid[2][0]=='B') count++;
        else    count--;
        if(grid[2][1]=='B') count++;
        else    count--;
        // cout<<count<<endl;
        if(count==2 || count==-2 || count==4 || count==-4)   return true;
        
        count=0;
        if(grid[1][1]=='B') count++;
        else    count--;
        if(grid[1][2]=='B') count++;
        else    count--;
        if(grid[2][1]=='B') count++;
        else    count--;
        if(grid[2][2]=='B') count++;
        else    count--;
        // cout<<count<<endl;
        if(count==2 || count==-2 || count==4 || count==-4)   return true;
        
        return false;
    }
};