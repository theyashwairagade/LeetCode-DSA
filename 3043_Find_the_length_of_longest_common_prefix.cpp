// But trie is difficult to implement in interview
// class TrieNode {
// public:
//     unordered_map<char, TrieNode*> children;
//     bool isEndOfWord;

//     TrieNode() {
//         isEndOfWord = false;
//     }
// };

// class Trie {
// private:
//     TrieNode* root;

// public:
//     Trie() 
//         {root = new TrieNode();}

//     void insert(const string &word) {
//         TrieNode* node = root;
//         for (char ch : word) 
//         {
//             if (node->children.find(ch) == node->children.end())
//                 node->children[ch] = new TrieNode();
//             node = node->children[ch];
//         }
//         node->isEndOfWord = true;
//     }

//     int longestCommonPrefix(const string &word) {
//         TrieNode* node = root;
//         int ans = 0;
//         for (char ch : word) 
//         {
//             if (node->children.find(ch) != node->children.end()) {
//                 ans++;
//                 node = node->children[ch];
//             }else
//                 break;
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         Trie myTrie;
//         int ans=0;
//         for(auto &i: arr1)
//             myTrie.insert(to_string(i));
//         for(auto &i: arr2)
//             ans=max(ans, myTrie.longestCommonPrefix(to_string(i)));
//         return ans;
//     }
// };





// So we are doing using set
struct DescendingLength {
    bool operator() (const string& a, const string& b) const {
        if (a.size() != b.size())
            return a.size() > b.size();
        return a < b; // Secondary criterion: lexicographical order
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string,DescendingLength> st;
        for(auto &i: arr1)
        {
            string str=to_string(i);
            while(str!="")
            {
                st.insert(str);
                str.pop_back();
            }
        }

        int ans=0;
        for(auto &i: arr2)
        {
            string str=to_string(i);
            while(str!="")
            {
                if(st.find(str)!=st.end())
                {
                    ans=max(ans, int(str.size()));
                    break;
                }
                else str.pop_back();
            }
        }
        return ans;
    }
};