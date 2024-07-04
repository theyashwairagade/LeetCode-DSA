class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (2*n-2);
        return (time < n) ? time+1 : 2*n-1-time;
    }
};