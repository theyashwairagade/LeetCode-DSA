class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        while(n>k){
            if((n&1) == (k&1)){
                n = n>>1;
                k = k>>1;
                continue;
            }
            if((n&1)==1){
                n = n>>1;
                k = k>>1;
                ans++;
                continue;
            }
            return -1;
        }
        if(n==k)
            return ans;
        // cout<<"main -1";
        return -1;
    }
};