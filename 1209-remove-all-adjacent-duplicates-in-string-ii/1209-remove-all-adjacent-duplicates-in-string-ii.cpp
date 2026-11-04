class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char c : s) {

            // If stack is empty or character is different
            if (st.empty() || st.top().first != c) {
                st.push({c, 1});
            }
            else {
                // Increase frequency of the same character
                st.top().second++;
            }

            // Remove k consecutive identical characters
            if (st.top().second == k) {
                st.pop();
            }
        }

        string ans = "";

        // Reconstruct the remaining string
        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            ans.append(it.second, it.first);
        }

        // Stack gives characters in reverse order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};