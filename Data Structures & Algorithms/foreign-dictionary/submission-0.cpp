class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (const string& word : words) {
            for (char ch : word) {
                adj[ch];          // Ensure every character exists in adj
                inDegree[ch] = 0; // Initialize in-degree to 0
            }
        }

        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());

            // Edge Case: Prefix violation (e.g., "apple" before "app")
            if (w1.length() > w2.length() && w1.rfind(w2, 0) == 0) {
                return "";
            }

            // Find the first differing character
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];
                    // Insert edge u -> v if not already added
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    break; // Only the first mismatch defines the order
                }
            }
        }

        // Step 3: Kahn's Algorithm (BFS Topological Sort)
        queue<char> q;
        for (const auto& [ch, deg] : inDegree) {
            if (deg == 0) {
                q.push(ch);
            }
        }

        string order = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check if all unique characters were included (Cycle detection)
        if (order.length() == inDegree.size()) {
            return order;
        }
        return "";
    }
};
