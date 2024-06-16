class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size(), ans = 0;
        for(int j = 1; j < n; j++)
            for(int i = 0; i < j; i++)
                if(((long long)hours[i]+hours[j])%24 == 0)
                    ans++;
        return ans;
    }
};