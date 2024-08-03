class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto &c: s){
            if(c=='a')
                stk.push(0);
            else if(c=='b')
                if(stk.size() && stk.top() == 0)
                    stk.push(1);
                else
                    stk.push(-1);
            else
                if(stk.empty() || stk.top()!=1)
                    return false;
                else{
                    stk.pop();
                    stk.pop();
                }
        }
        return stk.empty();
    }
};