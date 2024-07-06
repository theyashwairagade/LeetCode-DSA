class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long prev = 1, waitingTime = 0;
        for(auto &customer: customers)
            waitingTime += (prev = max((long long) customer[0], prev) + customer[1]) - customer[0];
        return (double)waitingTime / customers.size();
    }
};