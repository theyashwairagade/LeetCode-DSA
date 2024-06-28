class Solution {
    void solve(int index, int &target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(!target){
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size() || target<candidates[index])
            return ;
        
        // take
        target-=candidates[index];
        temp.push_back(candidates[index]);
        solve(index, target, candidates, temp, ans);
        temp.pop_back();
        target+= candidates[index];

        // not take
        solve(index+1, target, candidates, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, target, candidates, temp, ans);
        return ans;
    }
};