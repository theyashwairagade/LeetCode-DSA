class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_set<int> st;
        for(auto &i: answers)
            st.insert(i);
        int ans = 0;
        for(auto &i: st)
            ans+=i+1;
        return ans;
    }
};