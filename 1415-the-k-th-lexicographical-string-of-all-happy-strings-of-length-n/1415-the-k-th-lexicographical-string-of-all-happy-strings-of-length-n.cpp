class Solution {
public:
    vector<string> ans;

    void backtrack(string& temp, int n) {

        // If the string reaches length n, store it.
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        // Try characters in lexicographical order.
        for (char ch = 'a'; ch <= 'c'; ch++) {

            // Adjacent characters must be different.
            if (!temp.empty() && temp.back() == ch) {
                continue;
            }

            // Choose the current character.
            temp.push_back(ch);

            // Explore the next position.
            backtrack(temp, n);

            // Backtrack: remove the last character.
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {

        string temp = "";

        // Generate all happy strings in sorted order.
        backtrack(temp, n);

        // Return empty if fewer than k strings exist.
        if (ans.size() < k) {
            return "";
        }

        return ans[k - 1];
    }
};