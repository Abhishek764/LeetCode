class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Queue stores all initially rotten oranges
        queue<pair<int, int>> q;

        int fresh = 0;
        int minutes = 0;

        // Find all rotten and fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Four possible directions: down, up, right, left
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Process rotten oranges level by level
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;

            // Process all oranges that were rotten before this minute
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                // Check all four adjacent cells
                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check boundaries and fresh orange
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                        grid[nr][nc] == 1) {

                        // Make the fresh orange rotten
                        grid[nr][nc] = 2;
                        fresh--;

                        // Add it to the queue for the next minute
                        q.push({nr, nc});
                    }
                }
            }
        }

        // If fresh oranges remain, some could not be reached
        return fresh == 0 ? minutes : -1;
    }
};