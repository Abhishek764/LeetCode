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
    unordered_map<int, int> mp;
    int postIdx;

    TreeNode* solve(vector<int>& postorder, int left, int right) {
        // No elements to construct
        if (left > right) {
            return nullptr;
        }

        // Last element in postorder is the root
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = mp[rootVal];

        // Build right subtree first
        root->right = solve(postorder, mid + 1, right);

        // Build left subtree
        root->left = solve(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Store inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIdx = postorder.size() - 1;

        return solve(postorder, 0, inorder.size() - 1);
    }
};