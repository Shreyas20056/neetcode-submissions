class Solution {
public:
    bool dfs(vector<vector<char>>& board,
             vector<vector<bool>>& visited,
             string& word,
             int row,
             int col,
             int index)
    {
        // Entire word found
        if(index == word.length())
            return true;

        // Boundary check
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size())
            return false;

        // Already visited
        if(visited[row][col])
            return false;

        // Character mismatch
        if(board[row][col] != word[index])
            return false;

        // Mark current cell visited
        visited[row][col] = true;

        // Explore all 4 directions
        bool found =
            dfs(board, visited, word, row + 1, col, index + 1) || // Down
            dfs(board, visited, word, row - 1, col, index + 1) || // Up
            dfs(board, visited, word, row, col + 1, index + 1) || // Right
            dfs(board, visited, word, row, col - 1, index + 1);   // Left

        // Backtrack
        visited[row][col] = false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows,
                                     vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
