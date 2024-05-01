class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> anagramGroups;

        for (const string &given : strs) {
            string sortedStr = given;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(given);
        }

        // Collect the anagram groups from the map
        for (auto& group : anagramGroups) {
            answer.push_back(group.second);
        }

        return answer;
    }
};