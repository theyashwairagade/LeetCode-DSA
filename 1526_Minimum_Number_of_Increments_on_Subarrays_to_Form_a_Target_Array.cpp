class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0, ans = 0;
        for(auto &i: target){
            if(i>prev)
                ans+= (i-prev);
            prev = i;
        }
        return ans;
    }
};