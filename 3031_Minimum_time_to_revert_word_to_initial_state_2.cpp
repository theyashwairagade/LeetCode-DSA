class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length();
        int maxTime = (n - 1) / k + 1;
        for (int currentTime = 1; currentTime < maxTime; currentTime++) {
            bool conditionMet = false;
            for (int i = currentTime * k; i < n; i++) {
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
    vector<int> z_function(const string &s) {
        int n = s.size();
        vector<int> z(n);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
            if (z[i] > r - i + 1)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
};






class Solution {
    public:
        int minimumTimeToInitialState(string word, int k) {
        auto z = z_function(word);
        for (int i = k, n = word.size(); i < n; i += k)
            if (z[i] == n - i)
                return i / k;
        return (word.size() + k - 1) / k;
    }
    vector<int> z_function(const string &s) {
        int n = s.size();
        vector<int> z(n);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
            if (z[i] > r - i + 1)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
};