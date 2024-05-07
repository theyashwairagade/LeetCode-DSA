// Greedy approach with time complexity as O(n) ans space complexity as O(1)
class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size(), total = 0, sum = 0, start = 0;
        for (int i = 0; i < n; i++) {
            int difference=gas[i] - cost[i];
            total += difference;
            sum += difference;
            if (sum < 0) 
            {
                sum = 0;
                start = i + 1;
            }
        }
        return (total >= 0) ? start : -1;
    }
};
