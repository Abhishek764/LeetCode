class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> ans;

    // First DFS: Calculate reversals needed for root 0
    void dfs1(int node, int parent) {

        for (auto [child, cost] : adj[node]) {

            if (child == parent) {
                continue;
            }

            ans[0] += cost;

            dfs1(child, node);
        }
    }

    // Second DFS: Calculate answers for all other roots
    void dfs2(int node, int parent) {

        for (auto [child, cost] : adj[node]) {

            if (child == parent) {
                continue;
            }

            // Reroot the tree from node to child
            ans[child] = ans[node] + (cost == 1 ? -1 : 1);

            dfs2(child, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        adj.assign(n, {});

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        // Step 2: Initialize answer array
        ans.assign(n, 0);

        // Step 3: Calculate answer for root 0
        dfs1(0, -1);

        // Step 4: Calculate answers for every other node
        dfs2(0, -1);

        return ans;
    }
};