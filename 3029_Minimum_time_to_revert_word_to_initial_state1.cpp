class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int maxTime = (word.length() - 1) / k + 1;

        for (int currentTime = 1; currentTime < maxTime; currentTime++) {
            bool conditionMet = false;

            for (int i = currentTime * k; i < word.length(); i++) {
                if (word[i] != word[i - currentTime * k]) {
                    conditionMet = true;
                    break;
                }
            }

            if (!conditionMet) {
                return currentTime;
            }
        }

        return maxTime;
    }
};