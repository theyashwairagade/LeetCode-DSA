class Solution {
    void perform(int &ans, const string &log){
        if(log == "./")
            return;
        if(log == "../"){
            if(ans)
                ans--;
            return;
        }
        ans++;
    }
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto &log: logs)
            perform(ans, log);
        return ans;
    }
};