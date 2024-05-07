// Two pointer approach in time complexity of O(n) and space complexity of O(1)
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int start=0;
        int n=s.size();
        while(start<n)
        {
            while(start<n && s[start]==' ')   start++;
            if(start==n)  return ans;
            int len=0;
            for(int i=start+len;i<n && s[i]!=' ';i++) len++;
            if (!ans.empty()) ans = s.substr(start, len) + " " + ans;
            else ans = s.substr(start, len);
            start+=len;
        }
        return ans;
    }
};