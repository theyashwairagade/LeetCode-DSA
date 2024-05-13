class Solution {
public:
    static bool sortByValue(const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        string answer="";
        unordered_map<char,int> mapping;
        for(char character:s)   mapping[character]++;
        vector<pair<char, int>> myVector(mapping.begin(), mapping.end());
        sort(myVector.begin(), myVector.end(),sortByValue);
        for (const auto& pair : myVector) {
            int upper=pair.second;
            for(int i=0;i<upper;i++)
                answer+=pair.first;
        }
    return answer;
    }
};