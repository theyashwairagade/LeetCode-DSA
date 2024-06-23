class Solution {
    int addCycle(vector<bool> &visited, vector<int> &nums, int index)
    {
        int ans = 1, current = nums[index];
        visited[index]=true;
        while(current !=index)
        {
            visited[current]=true;
            ans ++;
            current = nums[current];
        }
        return ans;
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);

        int ans =0;
        for(int i=0; i<n; i++)
            if(!visited[i])
                ans = max(ans, addCycle(visited, nums, i)),
                visited[i]=true;

        return ans;
    }
};