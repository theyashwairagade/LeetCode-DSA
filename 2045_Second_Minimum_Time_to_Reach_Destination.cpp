// Can't perform normal BFS due to MLE
class Solution {
    vector<vector<int>> undirectedAdjacencyList(int n, vector<vector<int>>& edges){
        vector<vector<int>> vec(n);
        for(auto &edge: edges)
            vec[edge[0]].push_back(edge[1]),
            vec[edge[1]].push_back(edge[0]);
        return vec;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        auto adjacencyList = undirectedAdjacencyList(n+1, edges);
        set<int> storeAns;
        queue<pair<int,int>> q;
        q.push({0, 1});
        while(storeAns.size()!=2){
            int currTime = q.front().first, currNode = q.front().second;
            q.pop();
            if(currNode == n)
                storeAns.insert(currTime);
            
            int nextTime = currTime + time;
            if(currTime % (2*change) >= change)
                nextTime += (2*change) - (currTime % (2*change));
            
            for(auto &node: adjacencyList[currNode])
                q.push({nextTime, node});
        }
        return *storeAns.rbegin();
    }
};





// Reason for mle same data multiple times soln to reduce it by allowing visited instead of 01 to 012
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS setup
        queue<pair<int, int>> q; // {time, node}
        vector<int> first(n + 1, INT_MAX);
        vector<int> second(n + 1, INT_MAX);

        q.push({0, 1});
        first[1] = 0;

        while (!q.empty()) {
            auto [currentTime, node] = q.front();
            q.pop();

            int newTime = currentTime;
            // Handle the traffic signal
            if ((currentTime / change) % 2 == 1) { // If red signal
                newTime += change - (currentTime % change);
            }
            newTime += time; // Time to travel to the next node

            for (int neighbor : adj[node]) {
                if (newTime < first[neighbor]) {
                    second[neighbor] = first[neighbor];
                    first[neighbor] = newTime;
                    q.push({newTime, neighbor});
                } else if (newTime > first[neighbor] && newTime < second[neighbor]) {
                    second[neighbor] = newTime;
                    q.push({newTime, neighbor});
                }
            }
        }

        return second[n] == INT_MAX ? -1 : second[n];
    }
};





// Optimization but it gives tle
class Solution {
    vector<vector<int>> undirectedAdjacencyList(int n, vector<vector<int>>& edges){
        vector<vector<int>> vec(n);
        for(auto &edge: edges)
            vec[edge[0]].push_back(edge[1]),
            vec[edge[1]].push_back(edge[0]);
        return vec;
    }
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
            for(auto &node2: adjencyList[node])
                if(shortestDistance[node]+1< shortestDistance[node2])
                {
                    shortestDistance[node2]=shortestDistance[node]+1;
                    q.push({shortestDistance[node2],node2});
                }
        }
        return shortestDistance;
    }
    bool search(int target, int from, int &to, vector<bool> &visited, vector<vector<int>> &adjacencyList){
        if(visited[from])
            return false;
        if(!target)
            return from == to;
        visited[from]=true;
        for(auto node: adjacencyList[from])
            if(search(target-1, node, to, visited, adjacencyList))
                return true;
        return visited[from] = false;
    }
    int findVal(int steps, int time, int change){
        int ans = 0;
        int cycle = 2*change;
        for(int i=0; i<steps; i++){
            if(ans % cycle >= change)
                ans += cycle - (ans%cycle);
            ans += time;
        }
        return ans;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        auto adjacencyList = undirectedAdjacencyList(n+1, edges);
        int shortestDistance = dijkstra(adjacencyList, 1)[n];
        vector<bool> visited(n+1, false);
        bool justNext = search(shortestDistance+1, 1, n, visited, adjacencyList);
        // return -1;
        if(justNext)
            return findVal(shortestDistance+1, time, change);
        return findVal(shortestDistance+2, time, change);
    }
};