class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    // Helper function for recursive search with wildcard '.'
    bool searchInNode(const string& word, int index, TrieNode* curr) {
        if (!curr) return false;
        if (index == word.length()) return curr->isEnd;

        char ch = word[index];

        if (ch == '.') {
            // Wildcard: try every existing child branch
            for (int i = 0; i < 26; ++i) {
                if (curr->children[i] && searchInNode(word, index + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            // Normal character: move directly to the specific child
            return searchInNode(word, index + 1, curr->children[ch - 'a']);
        }
    }
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};
