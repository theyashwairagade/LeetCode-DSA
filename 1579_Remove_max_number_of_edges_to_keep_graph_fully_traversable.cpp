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
        {return findParent(x) == findParent(y);}
    
    // Default startingIndex is zero
    bool isFullyConnected(int startingIndex = 0){
        for(int i=startingIndex+1; i<parent.size(); i++)
            if(!isConnected(startingIndex,i))
                return false;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count = 0;
        DisjointSetByRank first(n+1);
        for(auto edge: edges)
        {
            int type = edge[0],
                u = edge[1],
                v = edge[2];
            if(type == 3 && !first.isConnected(u,v))
                first.connect(u,v),
                count++;
        }
        DisjointSetByRank second = first;
        for(auto edge: edges)
        {
            int type = edge[0],
                u = edge[1],
                v = edge[2];
            if(type == 1 && !first.isConnected(u,v))
                first.connect(u,v),
                count++;
            if(type == 2 && !second.isConnected(u,v))
                second.connect(u,v),
                count++;
        }
        
        if(!first.isFullyConnected(1) || !second.isFullyConnected(1))
            return -1;
        return edges.size()-count;
    }
};