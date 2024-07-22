class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<size_t> index(n);
        
        for(size_t i=0; i<n; i++)
            index[i]=i;

        sort(index.begin(), index.end(), 
            [&](size_t i, size_t j) {return heights[i]>heights[j];});

        vector<string> ans(n);
        
        for(size_t i=0; i<n; i++)
            ans[i]=names[index[i]];
        
        return ans;
    }
};