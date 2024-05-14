// DFS
class Solution {
public:
    bool study(vector<vector<int>> &matrix, vector<bool> &studied, vector<bool> &then, int subject)
    {
        if(studied[subject])
            return true;
        if(then[subject])
            return false;
        then[subject]=true;
        for(int &i: matrix[subject])
            if(!studied[i])
            {
                if(!study(matrix,studied,then,i))
                    return false;
            }
        then[subject]=false;
        studied[subject]=true;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(n);
        for(auto &vec: prerequisites)
            matrix[vec[0]].push_back(vec[1]);

        vector<bool> studied(n);
        for(int i=0; i<n; i++)
            if(!studied[i])
            {
                vector<bool> then(n);
                if(!study(matrix,studied,then,i))
                    return false;
            }
        return true;
    }
};





// BFS using kahn's algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(n);
        for(auto &vec: prerequisites)
            matrix[vec[0]].push_back(vec[1]);

        vector<int> inDegree(n);
        for(int i=0;i<n;i++)
            for(auto &j: matrix[i])
                inDegree[j]++;

        queue<int> noInDegree;
        for(int i=0;i<n;i++)
            if(!inDegree[i])
                noInDegree.push(i);
        
        int count=0;
        while(noInDegree.size())
        {
            int course=noInDegree.front();
            count++;
            noInDegree.pop();
            for(int &i: matrix[course])
            {
                inDegree[i]--;
                if(!inDegree[i])
                    noInDegree.push(i);
            }
        }
        return count==n;
    }
};