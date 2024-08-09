class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int n = values.size(), m = values[0].size();

        for(int i=0; i<n; i++)
            minHeap.push({values[i][m-1], i, m-1});
        
        long long ans = 0;
        for(int count = 1; minHeap.size(); count++){
            auto top = minHeap.top();
            minHeap.pop();

            ans += (long long)top[0] * count;
            if(top[2]){
                top[2]--;
                top[0] = values[top[1]][top[2]];
                minHeap.push(top);
            }
        }
        return ans;
    }
};





// Optimizing average case time complexity
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> vec;
        for(auto &v: values)
            for(auto &i: v)
                vec.push_back(i);
        
        sort(vec.begin(), vec.end());
        int n = values.size(), m = values[0].size();
        long long ans = 0;

        for(int i=1; i<=n*m; i++)
            ans += (long long)vec[i-1]*i;
        return ans;
    }
};