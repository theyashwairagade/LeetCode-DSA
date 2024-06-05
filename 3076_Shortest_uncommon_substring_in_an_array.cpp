struct CustomCompare {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs; // Lexicographical comparison if sizes are equal
        }
        return lhs.size() < rhs.size(); // Compare by size
    }
};
class Solution {
private: 
    unordered_set<string> unordered(string str)
    {
        int n=str.size();
        unordered_set<string> ans;
        for(int i=0; i<n; i++)
            for(int j=1; j<=n-i; j++)
                ans.insert(str.substr(i,j));
        return ans;
    }
    set<string,CustomCompare> ordered(string str)
    {
        int n=str.size();
        set<string,CustomCompare> ans;
        for(int i=0; i<n; i++)
            for(int j=1; j<=n-i; j++)
                ans.insert(str.substr(i,j));
        return ans;
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n=arr.size();
        vector<string> ans(n,"");

        unordered_map<string, int> freq;
        for(auto &str: arr)
        {
            unordered_set<string> st=unordered(str);
            for(auto &i: st)
                freq[i]++;
        }

        for(int i=0; i<n; i++)
        {
            set<string,CustomCompare> st=ordered(arr[i]);
            for(auto &subStr: st)
                if(freq[subStr]==1)
                {
                    ans[i]=subStr;
                    break;
                }
        }
        return ans;
    }
};