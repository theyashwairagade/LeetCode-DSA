class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for(auto &c: s)
            if(c=='(')
            {
                if(count)
                    ans+=c;
                count++;
            }else
            {
                if(count!=1)
                    ans+=c;
                count--;
            }
        return ans;
    }
};