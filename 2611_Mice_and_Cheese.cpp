class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum = 0;
        for(auto &i: reward2)
            sum+=i;
        int n = reward1.size();
        for(int i=0; i<n; i++)
            reward1[i]-=reward2[i];
        sort(reward1.begin(), reward1.end());
        reverse(reward1.begin(), reward1.end());
        for(int i=0; i<k; i++)
            sum+=reward1[i];
        return sum;
    }
};