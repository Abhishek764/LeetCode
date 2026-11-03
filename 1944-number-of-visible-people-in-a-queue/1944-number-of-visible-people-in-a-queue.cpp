class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        // Store the number of people each person can see
        vector<int> ans(n, 0);

        // Monotonic decreasing stack of heights
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Every shorter person can be seen
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                ans[i]++;
            }

            // The first taller person can also be seen
            if (!st.empty()) {
                ans[i]++;
            }

            // Add current person's height to the stack
            st.push(heights[i]);
        }

        return ans;
    }
};