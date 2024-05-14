// DFS
class Solution {
public:
    bool study(vector<vector<int>> &matrix, vector<int> &order, vector<bool> &studied, vector<bool> &then, int subject)
    {
        if(studied[subject])
            return true;
        if(then[subject])
            return false;
        then[subject]=true;
        for(int &i: matrix[subject])
            if(!studied[i])
            {
                if(!study(matrix,order,studied,then,i))
                {
                    cout<<"Can't study "<<i<<endl;
                    return false;
                }
            }
        then[subject]=false;
        studied[subject]=true;
        order.push_back(subject);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(n);
        for(auto &vec: prerequisites)
            matrix[vec[0]].push_back(vec[1]);

        vector<int> order;
        vector<bool> studied(n);
        for(int i=0; i<n; i++)
            if(!studied[i])
            {
                vector<bool> then(n);
                if(!study(matrix, order,studied,then,i))
                    return {};
            }
        return order;
    }
};





// BFS using kahn's algorithm
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
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
        
        vector<int> order;
        while(noInDegree.size())
        {
            int course=noInDegree.front();
            order.push_back(course);
            noInDegree.pop();
            for(int &i: matrix[course])
            {
                inDegree[i]--;
                if(!inDegree[i])
                    noInDegree.push(i);
            }
        }
        if(order.size()!=n)
            return {};
        reverse(order.begin(),order.end());
        return order;
    }
};