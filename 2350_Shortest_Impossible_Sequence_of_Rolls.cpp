// Time complexity of O(k+n logK) and space complexity of O(k)
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<pair<int,int>> st;
        vector<int> lastT(k+1, 0);

        for(int i=1; i<=k; i++)
            st.insert({0, i});
        
        reverse(rolls.begin(), rolls.end());
        for(auto &i: rolls){
            int newT = (*st.begin()).first + 1;
            st.erase({lastT[i],i});
            st.insert({newT, i});
            lastT[i]=newT;
        }
        return (*st.begin()).first+1;
    }
};





// Optimizing to time complexity of O(n) and space complexity of O(k)
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> st;
        int ans = 1;

        for(auto &i: rolls){
            st.insert(i);
            if(st.size()==k)
                ans++,
                st.clear();
        }
        return ans;
    }
};





// Instead of set use boolean to further optimize