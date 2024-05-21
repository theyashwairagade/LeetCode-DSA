class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int one=0;
        for(char character: s)  if(character=='1')  one++;
        for(int i=1;i<one;i++)  ans+="1";
        int length=s.size()-one;
        for(int i=0;i<length;i++)   ans+="0";
        ans+="1";
        return ans;
    }
};