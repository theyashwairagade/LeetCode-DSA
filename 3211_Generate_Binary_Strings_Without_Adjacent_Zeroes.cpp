class Solution {
    void solve(string &temp, int &n, vector<string> &ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        bool prevZero = (temp.size() && temp.back()=='0');

        if(!prevZero){
            temp +='0';
            solve(temp, n, ans);
            temp.pop_back();
        }
        temp += '1';
        solve(temp, n, ans);
        temp.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        string temp = "";
        vector<string> ans;

        solve(temp, n, ans);
        return ans;
    }
};