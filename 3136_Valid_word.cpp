class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)   return false;
        int vowels=0, digits=0, consonant=0;
        for(const auto &c: word)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
                vowels++;
            else if(isdigit(c))
                continue;
            else if(isalpha(c))
                consonant++;
            else
                return false;
        return vowels && consonant;
    }
};