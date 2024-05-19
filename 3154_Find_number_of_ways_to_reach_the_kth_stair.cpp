class Solution {
    unordered_map<int, vector<vector<int>>> memo;

    int findWays(int targetStep, int currentStep, int jumpPower, bool canJump) {
        if (currentStep > targetStep + 5)
            return 0;

        if (jumpPower > 31)
            return 0;

        if (memo.count(currentStep) && memo[currentStep][jumpPower][canJump] != -1)
            return memo[currentStep][jumpPower][canJump];
    
        int result = (currentStep == targetStep);

        if (canJump)
            result += findWays(targetStep, currentStep - 1, jumpPower, false);

        if (currentStep + (1 << jumpPower) <= targetStep + 1)
            result += findWays(targetStep, currentStep + (1 << jumpPower), jumpPower + 1, true);

        memo[currentStep].resize(32, vector<int>(2, -1));

        return memo[currentStep][jumpPower][canJump] = result;
    }

public:
    int waysToReachStair(int targetStep) {
        return findWays(targetStep, 1, 0, true);
    }
};