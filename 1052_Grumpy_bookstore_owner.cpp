// Brutte with time complexity of O(n square) and space complexity of O(1)
// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         int n = customers.size();
//         int maxAns = 0;
//         for (int i = 0; i < n; i++) {
//             int ans = 0;
//             for (int j = i; j < n && j < i + minutes; j++)
//                 if (grumpy[j])
//                     ans += customers[j];
//             maxAns = max(ans, maxAns);
//         }

//         for (int i = 0; i < n; i++)
//             if (!grumpy[i])
//                 maxAns += customers[i];
//         return maxAns;
//     }
// };





// Optimizing using sliding window concept
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int left = 0, right = 0;
        int maxAns = 0, tempAns = 0;
        while (right < n) {
            if (right - left + 1 < minutes){
                right++;
                if (right < n && grumpy[right])
                    tempAns += customers[right];
            } else{
                if(grumpy[left])
                    tempAns -= customers[left];
                left++;
            }
            maxAns = max (tempAns, maxAns);
        }

        for (int i = 0; i < n; i++)
            if (!grumpy[i])
                maxAns += customers[i];
        return maxAns;
    }
};