// Brutte force will give tle
// class Solution {
//     string subString(string &s, int left, int right)
//         {return s.substr(left, right-left+1);}
//     bool isPalindrome(string s)
//     {
//         for(int left=0, right = s.size()-1; left<right; left++, right--)
//             if(s[left]!=s[right])
//                 return false;
//         return true;
//     }
//     bool greater(string str, string ans)
//         {return str.size()>ans.size();}
// public:
//     string longestPalindrome(string s) {
//         string ans="";
//         int len=s.size();
//         for(int left=0; left<len; left++)
//             for(int right=left; right<len; right++)
//             {
//                 string str = subString(s, left, right);
//                 if(isPalindrome(str) && greater(str, ans))
//                     ans=str;
//             }
//         return ans;
//     }
// };





// optimized
class Solution {
    void update(string &s, string &ans, int left, int right)
    {
        if(left<0 || right >=s.size() || s[left]!=s[right])
            return;
        string tempAns=s.substr(left, right-left+1);
        if(tempAns.size()>ans.size())
            ans=tempAns;
        update(s, ans, left-1, right+1);
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        int len=s.size();
        for(int i=0; i<len; i++)
            update(s, ans, i, i),
            update(s, ans, i, i+1);
        return ans;
    }
};





// Most optimized solution is using manacher's algorithm with time complexity of O(n) and space complexity of O(1) but we don't need it for interview purpose