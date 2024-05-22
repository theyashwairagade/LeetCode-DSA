class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) return y-x;

        queue<pair<int,int>> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> dis;

        q.push({x,0});
        visited[x]=true;
        dis[x]=0;

        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();

                int node=p.first;
                int d=p.second;

                if ((node) > 1 && !visited[node - 1]) {
                    visited[node - 1] = true;
                    dis[node - 1] = d + 1;
                    q.push({node - 1, d + 1});
                }
                if (node % 5 == 0 && !visited[node / 5]) {
                    visited[node / 5] = true;
                    dis[node / 5] = d + 1;
                    q.push({node / 5, d + 1});
                }
                if (node % 11 == 0 && !visited[node / 11]) {
                    visited[node / 11] = true;
                    dis[node / 11] = d + 1;
                    q.push({node / 11, d + 1});
                }
                if (node < x + 15 && !visited[node + 1]) {
                    visited[node + 1] = true;
                    dis[node + 1] = d + 1;
                    q.push({node + 1, d + 1});
                }
            }
        }
        return dis[y];
    }
};