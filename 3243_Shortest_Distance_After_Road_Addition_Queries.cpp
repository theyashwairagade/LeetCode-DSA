class Solution {
    vector<int> dijkstra(vector<vector<int>> &adjencyList, int source)
    {
        int n=adjencyList.size();
        vector<int> shortestDistance(n,1e8);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, source});
        while(!q.empty())
        {
            int weight=q.top().first, node= q.top().second;
            q.pop();

            if(weight>shortestDistance[node])
                continue;
            
            shortestDistance[node]=weight;
            for(auto &entry: adjencyList[node])
            {
                int node2= entry;
                if(shortestDistance[node]+1< shortestDistance[node2])
                {
                    shortestDistance[node2]=shortestDistance[node]+1;
                    q.push({shortestDistance[node2],node2});
                }
            }
        }
        return shortestDistance;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjencyList(n);
        for(int i=0; i<n-1; i++)
            adjencyList[i].push_back(i+1);
        
        vector<int> ans;
        for(auto &query: queries){
            adjencyList[query[0]].push_back(query[1]);
            ans.push_back(dijkstra(adjencyList, 0)[n-1]);
        }
        return ans;
    }
};