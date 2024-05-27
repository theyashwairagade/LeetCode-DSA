class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &adjencyList, int source)
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
                int node2= entry.first, edgeWeight= entry.second;
                if(shortestDistance[node]+edgeWeight< shortestDistance[node2])
                {
                    shortestDistance[node2]=shortestDistance[node]+edgeWeight;
                    q.push({shortestDistance[node2],node2});
                }
            }
        }
        return shortestDistance;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjencyList(n);
        for(auto &edge: edges)
            adjencyList[edge[0]].push_back({edge[1], edge[2]}),
            adjencyList[edge[1]].push_back({edge[0], edge[2]});

        vector<int> sourceDistance= dijkstra(adjencyList, 0);
        vector<int> destinationDistance= dijkstra(adjencyList, n-1);

        int edgesSize=edges.size();
        vector<bool> ans(edgesSize, false);
        
        int minDistance= sourceDistance[n-1];
        for(int i=0; i<edgesSize; i++)
        {
            int node1= edges[i][0], node2= edges[i][1], edgeWeight= edges[i][2];
            if(
                sourceDistance[node1]+destinationDistance[node2]+edgeWeight== minDistance
                || sourceDistance[node2]+destinationDistance[node1]+edgeWeight== minDistance
                )
                ans[i]=true;
        }

        return ans;
    }
};