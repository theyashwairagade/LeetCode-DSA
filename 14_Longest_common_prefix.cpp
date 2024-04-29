class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int len=strs[0].size();
        for(string str:strs)
            if(str.size()<len)  len=str.size();
        for(int i=0;i<len;i++)
        {
            char current=strs[0][i];
            for(string str:strs)    if(str[i]!=current) return ans;
            ans+=current;
        }
        return ans;
    }
};

// more optimised
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;;i++)
        {
            int current=strs[0][i];
            for(string str:strs)
                if(str[i]=='\0' || str[i]!=current)    return ans;
            ans+=current;
        }
        return ans;
    }
};

// Solution by sorting
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++)
            if(strs[0][i]!=strs[strs.size()-1][i])  return strs[0].substr(0,i);
        return strs[0];
    }
};