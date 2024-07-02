class Trie {
private:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode() 
            {isEndOfWord = false;}
    };
    TrieNode* root;

    bool search(int index, const string &word, TrieNode* node) 
    {
        if(index == word.size())
            return node->isEndOfWord;
        
        if(word[index] == '.')
        {
            for(auto &pr: node->children)
            {
                bool possible = search(index+1, word, pr.second);
                if(possible)
                    return true;
            }
            return false;
        }
        if(node->children.find(word[index]) != node->children.end())
            return search(index+1, word, node->children[word[index]]);
        return false;
    }
public:
    Trie() 
        {root = new TrieNode();}

    void insert(const string &word) 
    {
        TrieNode* node = root;
        for (char ch : word) 
        {
            if (node->children.find(ch) == node->children.end())
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const string &word){
        return search(0, word, root);
    }
};

class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};