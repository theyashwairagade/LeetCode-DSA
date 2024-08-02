// Mistake in logic
class Solution {
    vector<int> findByMonotonicStack(vector<int> &vec){
        int n = vec.size();
        vector<int> nextGreater(n, -1);
        stack<int> stk;

        for(int i=0; i<n; i++){
            while(!stk.empty() && vec[stk.top()]<vec[i]){
                nextGreater[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return nextGreater;
    }
    // void print(vector<int> &vec){
    //     for(auto &i: vec)
    //         cout<<i<<" ";
    //     cout<<endl;
    // }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        auto nextGreaterElementIndex = findByMonotonicStack(heights);
        // print(nextGreaterElementIndex);

        vector<int> ans;
        for(auto &query: queries){
            int x = query[0], y = query[1];
            if(x>y)
                swap(x, y);
            if(x==y || heights[x]< heights[y])
                ans.push_back(y);
            else
                ans.push_back(nextGreaterElementIndex[x]);
        }
        return ans;
    }
};





// Youtube for logic
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        int heightLen = heights.size();
        vector<int> ans(n, -1);
        vector<vector<pair<int,int>>> queryStorage(heightLen);

        for(int i=0; i<n; i++){
            int a = queries[i][0], b = queries[i][1];
            if(a>b)
                swap(a,b);
            if(a==b || heights[a]< heights[b])
                ans[i] = b;
            else
                queryStorage[b].push_back({max(heights[a], heights[b]), i});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i = 0; i<heightLen; i++){
            int height = heights[i];
            while(minHeap.size() && minHeap.top().first<height){
                ans[minHeap.top().second]=i;
                minHeap.pop();
            }
            for(auto query: queryStorage[i])
                minHeap.push(query);
        }
        return ans;
    }
};