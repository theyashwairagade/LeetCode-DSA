class Solution {
    int intVal(string &str){
        if(str.empty())
            return 1;
        int ans = 0;
        for(auto &digit: str){
            ans *= 10;
            ans += digit-(int) '0';
        }
        return ans;
        // return max(1, ans);
    }
    void addPrevEntry(stack<pair<string,int>> &stk, string &element, string &digits){
        if(element.empty())
            return;
        stk.push({element, intVal(digits)});
        element = "", digits = "";
    }
    void solveVectorProblem(stack<pair<string,int>> &stk, vector<pair<string, int>> &vec, string &digits){
        if(vec.empty())
            return;
        int multiplier = intVal(digits);
        digits = "";

        for(auto &pr: vec){
            pr.second *= multiplier;
            stk.push(pr);
        }
        vec.clear();
    }
    bool capitalLetter(char &c)
        {return c >= 'A' && c <= 'Z';}
    bool smallLetter(char &c)
        {return c >= 'a' && c <= 'z';}
    bool digit(char &c)
        {return c>='0' && c<='9';}
public:
    string countOfAtoms(string formula) {
        string element = "", digits = "";
        stack<pair<string, int>> stk;
        vector<pair<string, int>> vec;

        for(auto &c: formula){
            if(c == '('){
                addPrevEntry(stk, element, digits);
                solveVectorProblem(stk, vec, digits);
                stk.push(make_pair("(", -1));
                continue;
            }
            if(capitalLetter(c)){
                addPrevEntry(stk, element, digits);
                solveVectorProblem(stk, vec, digits);
                element = c;
                continue;
            }
            if(smallLetter(c)){
                element +=c;
                continue;
            }
            if(digit(c)){
                digits +=c;
                continue;
            }
            addPrevEntry(stk, element, digits);
            solveVectorProblem(stk, vec, digits);
            while(stk.top().first != "("){
                vec.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        addPrevEntry(stk, element, digits);
        solveVectorProblem(stk, vec, digits);

        map<string,int> mp;
        while(!stk.empty()){
            mp[stk.top().first]+=stk.top().second;
            stk.pop();
        }

        string ans = "";
        for(auto &pr: mp){
            ans += pr.first;
            if(pr.second>1)
                ans += to_string(pr.second);
        }
        return ans;
    }
};