class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lowerCase, upperCase, special;
        for(char &c: word)
            if(islower(c))
                lowerCase.insert(c);
            else
                upperCase.insert(c);
        
        for(char &c: word)
            if(islower(c) && upperCase.find(toupper(c))!=upperCase.end())
                special.insert(c);
            else if(isupper(c) && lowerCase.find(tolower(c))!=lowerCase.end())
                special.insert(tolower(c));
        return special.size();
    }
};