// Time complexity of O(6n) and space complexity of O(4n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        // Removing first top substrings cause they give more points
        vector<char> stack;
        for (char ch : s) {  // Changed 'char' to 'ch'
            if (ch == top[1] && !stack.empty() && stack.back() == top[0]) {
                res += top_score;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        // Removing bot substrings cause they give less or equal amount of scores
        vector<char> new_stack;
        for (char ch : stack) {  // Changed 'char' to 'ch'
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                res += bot_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }

        return res;
    }
};





// Optimizing time complexity to O(4n) and space complexity to O(2n)
class Solution {
public:
    int removePairs(string &s, string target) {
        int write_ind = 0, count = 0;
        for (char c : s) {
            s[write_ind] = c;
            write_ind++;
            if (write_ind >= 2 && s[write_ind - 1] == target[1] && s[write_ind - 2] == target[0]) {
                count++;
                write_ind -= 2;
            }
        }
        s.resize(write_ind);
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        res += removePairs(s, top) * top_score;
        res += removePairs(s, bot) * bot_score;
        return res;
    }
};