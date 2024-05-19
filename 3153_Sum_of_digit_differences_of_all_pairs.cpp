class Solution {
public:
    long long sumDigitDifferences(vector<int>& numbers) {
        int digitCount = int(to_string(numbers[0]).size());

        vector<vector<int>> digitFrequency(digitCount, vector<int>(10, 0));

        for (int number : numbers) 
        {
            string numStr = to_string(number);
            for (int pos = 0; pos < numStr.size(); ++pos)
                digitFrequency[pos][numStr[pos] - '0']++;
        }

        long long differenceSum = 0;
        for (int number : numbers) 
        {
            string numStr = to_string(number);
            for (int pos = 0; pos < numStr.size(); ++pos) 
            {
                int currentDigit = numStr[pos] - '0';
                for (int digit = 0; digit < 10; ++digit) 
                    if (digit != currentDigit) 
                        differenceSum += digitFrequency[pos][digit];
            }
        }
        return differenceSum / 2;
    }
};