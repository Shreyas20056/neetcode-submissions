class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = ""; // Holds the complete word if this node ends a word
    };

    TrieNode* root;

    // Standard Trie Insert
    void insert(const string& w) {
        TrieNode* curr = root;
        for (char ch : w) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = w; // Store the word directly at the ending node
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];

        // Base checks: visited cell or character not in current Trie path
        if (ch == '#' || !curr->children[ch - 'a']) return;

        curr = curr->children[ch - 'a'];

        // If a word ends at this node, collect it
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; // Prevent duplicate additions
        }

        // Mark cell as visited
        board[r][c] = '#';

        // Explore 4 directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, curr, result);
            }
        }

        // Backtrack: restore original character
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const string& w : words) {
            insert(w);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};
