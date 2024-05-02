class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        int start=s.size()-1;
        while(start>=0)
        {
            if(s[start]!=' ')   break;
            start--;
        }
        while(start>=0)
        {
            if(s[start]==' ')   break;
            start--;
            length++;
        }
        return length;
    }
};