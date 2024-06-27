class Solution {
    void solve(int index, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans, vector<int> &nums)
    {
        int n = nums.size();
        if(index == n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                visited[i]=true;
                temp.push_back(nums[i]);
                solve(index+1, temp, visited, ans, nums);
                temp.pop_back();
                visited[i]=false;
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        solve(0, temp, visited, ans, nums);
        return ans;
    }
};





// We can optimized space complexity by using swapping thing so we won't be required visited and temp vector