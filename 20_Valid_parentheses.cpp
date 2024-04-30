class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for (char a : s) {
            if (a == '(' || a == '[' || a == '{') {
                v.push(a); // Push opening brackets onto the stack
            } else {
                if (v.empty()) {
                    return false; // No corresponding opening bracket found
                }
                char top = v.top(); // Get the top element from the stack
                v.pop(); // Pop the top element
                if ((a == ')' && top != '(') ||
                    (a == ']' && top != '[') ||
                    (a == '}' && top != '{')) {
                    return false; // Mismatched brackets
                }
            }
        }
        return v.empty(); // Return true if the stack is empty at the end
    }
};