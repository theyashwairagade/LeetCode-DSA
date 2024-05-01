class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(const char &c: text)
            mp[c]++;
        return min(min(min(mp['a'],mp['b']),min(mp['n'],mp['o']/2)),mp['l']/2);
    }
};