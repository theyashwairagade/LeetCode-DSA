class Solution {
public:
    void swap(char &c)
        {c=c=='1'?'2':'1';}
    bool bfs(vector<vector<int>>& graph, vector<char> &color, int &node)
    {
        char currentColor='1';
        queue<int> q;
        q.push(node);
        q.push(-1);
        while(q.size()>1)
        {
            int top=q.front();
            q.pop();
            if(top==-1)
            {
                swap(currentColor);
                q.push(-1);
                continue;
            }
            if(color[top]==currentColor)
                continue;
            if(color[top]=='0')
            {
                color[top]=currentColor;
                for(int &i: graph[top])
                    q.push(i);
                continue;
            }
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<char> color(n,'0');
        for(int i=0; i<n; i++)
            if(color[i]=='0' && !bfs(graph,color,i))
                return false;
        return true;
    }
};