class Solution {
    void solve(int &openedBraces, int &remainBraces, string &temp, vector<string> &ans){
        if(!openedBraces && !remainBraces)
        {
            ans.push_back(temp);
            return;
        }

        if(remainBraces){
            openedBraces++;
            remainBraces--;
            temp.push_back('(');
            solve(openedBraces, remainBraces, temp, ans);
            temp.pop_back();
            remainBraces++;
            openedBraces--;
        }
        if(openedBraces){
            openedBraces--;
            temp.push_back(')');
            solve(openedBraces, remainBraces, temp, ans);
            temp.pop_back();
            openedBraces++;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        int openedBraces = 0;
        solve(openedBraces, n, temp, ans);
        return ans;
    }
};