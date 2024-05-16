// Approach 1: With the help of modulo operator we can implement brutte force method with time complexity of O(n square)

// Approach 2: appernd array at end of itself, Now using sliding window concept with max window size of N. We can implement this approach with time complexity of O(n) and space complexity of O(n). NOTE: Difficult to implement as there may be several corner cases.


// Approach 3: Return sum of all elements in array - minimum sum subarray. Corner case is when all elements are negative return minimum element.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int arraySum=0,maxSum=0,minSum=0;
        int maxAns=INT_MIN,minAns=INT_MAX;   
        
        for(auto num:nums)
        {
            arraySum+=num;
            maxSum+=num;
            minSum+=num;

            maxAns=max(maxAns,maxSum);
            minAns=min(minSum,minAns);

            maxSum=max(0,maxSum);
            minSum=min(0,minSum);
        }

        bool allElementsAreNegative=(arraySum==minAns);
        if(allElementsAreNegative)  return maxAns;
        return max(maxAns,arraySum-minAns);
    }
};