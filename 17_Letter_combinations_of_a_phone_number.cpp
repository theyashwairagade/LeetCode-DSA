class Solution {
    void solve(vector<string> &ans, vector<string> &mp, string &digits, string &temp, int index){
        if(index == digits.size()){
            ans.push_back(temp);
            return ;
        }
        for(auto &i: mp[digits[index]-'2'])
        {
            temp.push_back(i);
            solve(ans, mp, digits, temp, index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> ans;
        string temp;
        vector<string> mp= {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, mp, digits, temp, 0);
        return ans;
    }
};