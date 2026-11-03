class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Stop if out of bounds or current cell is water
        if (i < 0 || j < 0 || i >= grid.size() ||
            j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        // Mark the visited land as water
        grid[i][j] = '0';

        // Explore all four adjacent directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        // Traverse every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start DFS whenever unvisited land is found
                if (grid[i][j] == '1') {
                    islands++;

                    // Visit the entire connected island
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};