class Solution {
    void print(vector<int> &vec){
        for(auto &i: vec)
            cout<<i<<" ";
        cout<<endl;
    }
    void print(vector<vector<int>> &vec){
        for(auto &i: vec)
            print(i);
    }
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> greaterThan(n, vector<int> (n, 0)), lesserThan(n, vector<int> (n, 0));

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++)
                greaterThan[i][j]=greaterThan[i][j-1] + (nums[j]>nums[i] ? 1 : 0);
    
            for(int j=i-1; j>=0; j--)
                lesserThan[i][j] = lesserThan[i][j+1] + (nums[j]<nums[i] ? 1 : 0);
        }
        // cout<<"greater than "<<endl;
        // print(greaterThan);
        // cout<<"lesser than "<<endl;
        // print(lesserThan);
        
        long long ans = 0;
        for(int j=1; j<n-2; j++)
            for(int k = j+1; k<n-1; k++)
                if(nums[j]>nums[k]){
                    int possibleLeft = lesserThan[k][0] - lesserThan[k][j];
                    int possibleRight = greaterThan[j][n-1]-greaterThan[j][k];
                    ans += (long long) possibleLeft * possibleRight;
                }
        return ans;
    }
};