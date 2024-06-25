class Solution {
    void maximum(pair<int,int> &to, pair<int,int> have){
        if(have.first>to.first)
            to.first = have.first,
            to.second = have.second;
    }
    vector<vector<int>> undirectedAdjacencyList(int n, vector<vector<int>>& edges){
        vector<vector<int>> vec(n);
        for(auto &edge: edges)
            vec[edge[0]].push_back(edge[1]),
            vec[edge[1]].push_back(edge[0]);
        return vec;
    }
    void reset(vector<bool> &vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            vec[i] = false;
        }
    }
    // distance, node
    pair<int,int> extremeEnd(vector<vector<int>> &adjacencyList, vector<bool> &visited, int node){
        visited[node]=true;
        pair<int, int> ans={0,-1};

        for(auto &child: adjacencyList[node])
            if(!visited[child])
                maximum(ans, extremeEnd(adjacencyList, visited, child));

        if(!ans.first)
            return {1,node};
        ans.first++;
        return ans;
    }
    void dereference(int &a, int &b, pair<int, int> pr){
        a=pr.first,
        b=pr.second;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        
        auto graph1AdjacencyList = undirectedAdjacencyList(n, edges1),
             graph2AdjacencyList = undirectedAdjacencyList(m, edges2);
        
        vector<bool> graph1Visited(n), graph2Visited(m);

        int diameter1, diameter2, node;
        dereference(diameter1, node, extremeEnd(graph1AdjacencyList,graph1Visited, 0));
        reset(graph1Visited);
        dereference(diameter1, node, extremeEnd(graph1AdjacencyList,graph1Visited, node));

        dereference(diameter2, node, extremeEnd(graph2AdjacencyList,graph2Visited, 0));
        reset(graph2Visited);
        dereference(diameter2, node, extremeEnd(graph2AdjacencyList,graph2Visited, node));
        
        return max(max(diameter1-1,diameter2-1),((diameter1/2)+(diameter2/2)+1));
    }
};