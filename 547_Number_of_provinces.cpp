// Looks quite complex as made by me
class Solution {
public:
    int allVisited(vector<bool> &visited, int index,int &n)
    {
        while(index<n)
            if(visited[index])
                index++;
            else
                return index;
        return 0;
    }
    void dfs(vector<vector<int>> &isConnected, int index, vector<bool> &visited, int &n)
    {
        if(visited[index])
            return;
        visited[index]=true;
        for(int i=0;i<n;i++)
            if(isConnected[index][i] && !visited[i])
                dfs(isConnected,i,visited,n);
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        dfs(isConnected, 0, visited, n);
        int ans=1;
        int notallVisited=allVisited(visited,0, n);
        while(notallVisited)
        {
            ans++;
            dfs(isConnected, notallVisited, visited, n);
            notallVisited=allVisited(visited, notallVisited, n);
        }
        return ans;
    }
};





// Made the code simpler
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int index, vector<bool> &visited, int &n)
    {
        if(visited[index])
            return;
        visited[index]=true;
        for(int i=0;i<n;i++)
            if(isConnected[index][i] && !visited[i])
                dfs(isConnected,i,visited,n);
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
            if(!visited[i])
                ans++,
                dfs(isConnected, i, visited, n);
        return ans;
    }
};