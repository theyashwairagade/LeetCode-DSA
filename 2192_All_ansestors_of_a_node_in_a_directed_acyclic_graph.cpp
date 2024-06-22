class Solution {
    void dfs(int node, vector<int> &ans, vector<bool> &visited, vector<vector<int>> &directedAcyclicAdjacencyList)
    {
        if(visited[node])
            return;
        visited[node]=true;

        for(auto &child: directedAcyclicAdjacencyList[node])
            dfs(child, ans, visited, directedAcyclicAdjacencyList);
            
        ans.push_back(node);
    }
    vector<int> topologicalSort(vector<vector<int>> &directedAcyclicAdjacencyList)
    {
        int n = directedAcyclicAdjacencyList.size();

        vector<int> ans;
        vector<bool> visited(n);

        for(int i=0; i<n; i++)
            dfs(i, ans, visited, directedAcyclicAdjacencyList);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<vector<int>> directedAdjacencyList(int n, vector<vector<int>>& edges){
        vector<vector<int>> vec(n);
        for(auto &edge: edges)
            vec[edge[0]].push_back(edge[1]);
        return vec;
    }
    vector<int> uniqueElements(vector<int> &sortedVec){
        int n= sortedVec.size();
        if(!n)
            return {};

        vector<int> ans;
        ans.push_back(sortedVec.front());
        int prev = sortedVec.front();

        for(int i=1; i<n; i++)
            if(sortedVec[i]!=prev)
                ans.push_back(prev = sortedVec[i]);
        
        return ans;
    }
    void pushBack(vector<int> &from, vector<int> &to)
    {
        for(auto &i: from)
            to.push_back(i);
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        auto adjacencyList = directedAdjacencyList(n,edges);
        auto topologicalOrder = topologicalSort(adjacencyList); //heart of question

        vector<vector<int>> ans(n);
        for(auto &node: topologicalOrder)
        {
            sort(ans[node].begin(), ans[node].end());
            ans[node]= uniqueElements(ans[node]); // due to edge cases

            for(auto &child: adjacencyList[node])
            {
                ans[child].push_back(node);
                pushBack(ans[node], ans[child]);
            }
        }

        return ans;
    }
};