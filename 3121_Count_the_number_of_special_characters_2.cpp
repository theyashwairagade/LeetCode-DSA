class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lowerCase, upperCase, special, banned;
        for(char &c: word)
            if(islower(c))
            {
                lowerCase.insert(c);
                if(upperCase.find(toupper(c))!=upperCase.end())
                    banned.insert(toupper(c));
            }
            else
            {
                upperCase.insert(c);
                if(lowerCase.find(tolower(c))!=lowerCase.end())
                        special.insert(c);
            }
        
        for(auto &c: banned)
            special.erase(c);
        return special.size();
    }
};