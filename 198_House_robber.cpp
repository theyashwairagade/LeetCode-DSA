class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=0,next=0,rob=0;
        for(int i:nums){
            rob=max(i+next,prev);
            next=prev;
            prev=rob;
        }
        return rob;
    }
};