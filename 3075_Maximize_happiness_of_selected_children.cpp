bool compare(int a, int b) {
    return a > b; // Change to a < b for ascending order
}
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), compare);
        int n=happiness.size();

        long long ans=0;
        for(int i=0; i<n && k>0; i++)
        {
            int happy= max(happiness[i]-i, 0);
            if(!happy)
                return ans;
            ans+=happy;
            k--;
        }
        return ans;
    }
};