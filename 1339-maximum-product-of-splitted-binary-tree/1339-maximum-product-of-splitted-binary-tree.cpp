/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const long long MOD = 1e9 + 7;

        vector<TreeNode*> nodes;
        stack<TreeNode*> st;

        long long totalSum = 0;

        // First traversal: Calculate total sum
        // and collect all nodes.
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            nodes.push_back(node);
            totalSum += node->val;

            if (node->left) {
                st.push(node->left);
            }

            if (node->right) {
                st.push(node->right);
            }
        }

        unordered_map<TreeNode*, long long> subtreeSum;

        long long maxProduct = 0;

        // Reverse traversal: Children before parents.
        for (int i = nodes.size() - 1; i >= 0; i--) {
            TreeNode* node = nodes[i];

            long long sum = node->val;

            if (node->left) {
                sum += subtreeSum[node->left];
            }

            if (node->right) {
                sum += subtreeSum[node->right];
            }

            subtreeSum[node] = sum;

            // Skip root because it has no parent edge.
            if (node != root) {
                long long product = sum * (totalSum - sum);

                maxProduct = max(maxProduct, product);
            }
        }

        return maxProduct % MOD;
    }
};