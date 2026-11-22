class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, int n, int k) {

        // If k elements are selected, store the combination.
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Choose numbers from start to n.
        for (int i = start; i <= n; i++) {

            // Select the current number.
            temp.push_back(i);

            // Recursively select the next number.
            backtrack(i + 1, n, k);

            // Backtrack: remove the last selected number.
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        backtrack(1, n, k);

        return ans;
    }
};