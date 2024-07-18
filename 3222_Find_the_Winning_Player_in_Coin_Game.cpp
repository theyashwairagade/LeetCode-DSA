class Solution {
public:
    string losingPlayer(int x, int y) {
        int search = min(x, y/4);
        if(search%2)
            return "Alice";
        return "Bob";
    }
};