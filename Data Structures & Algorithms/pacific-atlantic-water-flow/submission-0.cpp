
class Solution {
public:
    void dfs(int r, int c, int n, int m, vector<vector<bool>>& reachable, vector<vector<int>>& heights) {
        reachable[r][c] = true;
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dRow[i];
            int nc = c + dCol[i];
            
            // Check boundary, not yet visited, and uphill flow (neighbor >= current)
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !reachable[nr][nc]) {
                if (heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, n, m, reachable, heights);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        // 1. Traverse Pacific & Atlantic boundaries
        // Top and Bottom borders
        for (int c = 0; c < m; c++) {
            dfs(0, c, n, m, pacific, heights);        // Top row -> Pacific
            dfs(n - 1, c, n, m, atlantic, heights);    // Bottom row -> Atlantic
        }
        
        // Left and Right borders
        for (int r = 0; r < n; r++) {
            dfs(r, 0, n, m, pacific, heights);        // Left col -> Pacific
            dfs(r, m - 1, n, m, atlantic, heights);    // Right col -> Atlantic
        }
        
        // 2. Collect coordinates where both oceans can reach
        vector<vector<int>> result;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};