// class Solution {
//     bool isVowel(char c)
//         {return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');}
// public:
//     string sortVowels(string s) {
//         string vowels="";
//         for(char &c: s)
//             if(isVowel(tolower(c)))
//                 vowels+=c;
        
//         sort(vowels.begin(), vowels.end());
//         int index = 0;
//         for(auto &c: s)
//             if(isVowel(tolower(c)))
//                 c=vowels[index++];
//         return s;
//     }
// };





// optimizing further using bucket sort i.e. time complexity of O(n)
class Solution {
    bool isVowel(char c)
        {return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');}
public:
    string sortVowels(string s) {
        string vowels="AEIOUaeiou";
        unordered_map<char,int> countVowel;
        for(char &c: s)
            if(isVowel(tolower(c)))
                countVowel[c]++;
        
        int index = 0;
        while(index < vowels.size() && countVowel[vowels[index]]==0)
            index++;

        for(auto &c: s)
            if(isVowel(tolower(c)))
            {
                c=vowels[index],
                countVowel[vowels[index]]--;
                while(index < vowels.size() && !countVowel[vowels[index]])
                    index++;
            }
        return s;
    }
};





// we can reduce time of isVowel function by using unordered_set
