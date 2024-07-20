class Solution {
public:
    bool doesAliceWin(string s) {
        int countVowels = 0;
        int earlierConsonants = 0;
        int lastConsonants = 0;
        for(auto &c: s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                countVowels++,
                lastConsonants = 0;
            else{
                if(!countVowels)
                    earlierConsonants++;
                lastConsonants++;
            }
        return (countVowels%2) ? true : ((earlierConsonants>1 && lastConsonants>1)? false : true);
    }
};



class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto &c: s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                return true;
        return false;
    }
};