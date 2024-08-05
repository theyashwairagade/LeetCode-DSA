class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 1;
        long long val = 0;
        for(auto &i: s){
            int curr = i-'0';
            if(val*10+curr<=k)
                val = val*10 + curr;
            else if(curr<=k)
                val = curr,
                ans++;
            else
                return -1;
        }
        return ans;
    }
};