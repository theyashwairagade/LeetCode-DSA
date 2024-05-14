// DFS
// class Solution {
// public:
//     void checkSafe(vector<vector<int>>& graph, vector<bool> &safe, vector<bool> &checkedSafe, int state)
//     {
//         if(checkedSafe[state])
//             return ;
//         checkedSafe[state]=true;
//         for(int &i: graph[state])
//         {
//             if(!checkedSafe[i])
//                 checkSafe(graph, safe,checkedSafe, i);
//             if(!safe[i])
//                 return;
//         }
//         safe[state]=true;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<bool> safe(n), checkedSafe(n);
//         for(int i=0;i<n;i++)
//             if(!checkedSafe[i])
//                 checkSafe(graph, safe, checkedSafe, i);
//         vector<int> safeStates;
//         for(int i=0;i<n;i++)
//             if(safe[i])
//                 safeStates.push_back(i);
//         return safeStates;
//     }
// };





// BFS using topological sort
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& originalGraph) {
        int n=originalGraph.size();
        vector<vector<int>> reverseGraph(n);
        for(int i=0;i<n;i++)
            for(auto &j: originalGraph[i])
                reverseGraph[j].push_back(i);
        
        vector<int> inDegree(n);
        for(int i=0;i<n;i++)
            for(auto &j: reverseGraph[i])
                inDegree[j]++;

        queue<int> noInDegree;
        for(int i=0;i<n;i++)
            if(!inDegree[i])
                noInDegree.push(i);
        
        vector<int> order;
        while(noInDegree.size())
        {
            int course=noInDegree.front();
            order.push_back(course);
            noInDegree.pop();
            for(int &i: reverseGraph[course])
            {
                inDegree[i]--;
                if(!inDegree[i])
                    noInDegree.push(i);
            }
        }
        sort(order.begin(),order.end());
        return order;
    }
};