// Brutte Force time complexity of O(n) and space complexity of O(1)
class Solution {
public:
    char addition(char a, char b, bool &remainder)
    {
        if(remainder)
        {
            if(a=='1' && b=='1')    return '1';
            if(a=='1' || b=='1')    return '0';
            remainder=false;
            return '1';
        }
        if(a=='1' && b=='1')
        {
            remainder=true;
            return '0';
        }
        if(a=='1' || b=='1')    return '1';
        return '0';
    }
    string addBinary(string a, string b) {
        string ans="";
        bool remainder=false;
        int lenA=a.size(), lenB=b.size();
        while(lenA>0 || lenB>0 || remainder)
        {
            char charA, charB;
            if(lenA>0)  charA=a[--lenA];
            else    charA='0';

            if(lenB>0)  charB=b[--lenB];
            else    charB='0';

            ans=addition(charA,charB,remainder)+ans;
        }
        return ans;
    }
};