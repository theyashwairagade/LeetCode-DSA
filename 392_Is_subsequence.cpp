class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl=s.size(), tl=t.size();
        int sp=0,tp=0;
        while(sp<sl && tp<tl)
        {
            if(s[sp]==t[tp])    sp++,tp++;
            else    tp++;
        }
        if(sp==sl)  return true;
        else    return false;
    }
};