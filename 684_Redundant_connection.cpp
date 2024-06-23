class Solution {
    class DisjointSetByRank {
        vector<int> parent, rank;
    public:
        DisjointSetByRank(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) 
                parent[i] = i;
        }

        int findParent(int x) {
            if (parent[x] != x) 
                parent[x] = findParent(parent[x]); // Path compression
            
            return parent[x];
        }

        void connect(int x, int y) {
            int rootX = findParent(x);
            int rootY = findParent(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY])
                    parent[rootY] = rootX;
                else if (rank[rootX] < rank[rootY])
                    parent[rootX] = rootY;
                else
                    parent[rootY] = rootX,
                    rank[rootX]++;
            }
        }
        bool isConnected(int x, int y)
            {return findParent(x)==findParent(y);}
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSetByRank disjointSet(n+1); // 1 indexing

        for(auto &edge: edges)
            if(!disjointSet.isConnected(edge[0], edge[1]))
                disjointSet.connect(edge[0], edge[1]);
            else
                return edge;
        return {-1, -1};
    }
};