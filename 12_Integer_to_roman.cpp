// Array of string for each 1's, 10's, 100's, 1000's in time complexity of O(1) and space complexity of O(1)
// class Solution {
// public:
//     string intToRoman(int num) {
//         string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
//         string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
//         string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
//         string ths[]={"","M","MM","MMM"};
        
//         return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
//     }
// };

// Using divide and modulo for each symbol and it's value int time complexity of O(1) and space complexity of O(1)
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> symbols={
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}};
        string ans="";
        for(auto pr:symbols)
        {
            for(int i=0;i<num/pr.second;i++)    ans+=pr.first;
            num%=pr.second;
        }
        return ans;
    }
};