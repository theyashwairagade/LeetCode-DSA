class Solution {
public:
    bool isSubstringPresent(string s) {
        int n=s.size()-1;
        if(n<1) return false;
        unordered_set<string> st;
        for(int i=0;i<n;i++)
            st.insert(s.substr(i,2)); //1
        
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++)
            if(st.find(s.substr(i,2))!=st.end())    return true;
        return false;
    }
};