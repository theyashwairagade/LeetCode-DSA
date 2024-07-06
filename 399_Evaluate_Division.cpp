class Solution {
    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>> &equations, const vector<double> &values){
        unordered_map<string, unordered_map<string, double>> graph;
        
        for(int i=0; i<equations.size(); i++){
            auto a = equations[i][0], b = equations[i][1];
            auto value = values[i];

            graph[a][b]= value,
            graph[b][a]= 1/value;
        }
        return graph;
    }

    void dfs(string node, const string &destination, const unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited, double &ans, double temp){
        if(visited.find(node) != visited.end())
            return;

        visited.insert(node);
        if(node == destination){
            ans = temp;
            return ;
        }

        for(const auto ne: graph.at(node))
            dfs(ne.first, destination, graph, visited, ans, temp * ne.second);
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto graph = buildGraph(equations, values);
        vector<double> finalAns;

        for(const auto &query: queries){
            auto a = query[0], b = query[1];

            if(graph.find(a) == graph.end() || graph.find(b) == graph.end()){
                finalAns.push_back(-1);
                continue;
            }

            unordered_set<string> visited;
            double ans = -1, temp = 1;
            dfs(a, b, graph, visited, ans, temp);
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};