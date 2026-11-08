class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // Store indices of bars in increasing order of their heights
        stack<int> st;

        // Store the maximum rectangle area found so far
        int maxArea = 0;

        // Get the total number of bars
        int n = heights.size();

        // Traverse all bars and one extra virtual bar
        for (int i = 0; i <= n; i++) {

            // Use -1 as a virtual bar to process remaining stack elements
            int currHeight = (i == n) ? -1 : heights[i];

            // Remove taller bars because their right boundary is found
            while (!st.empty() && heights[st.top()] > currHeight) {

                // Get the height of the rectangle
                int height = heights[st.top()];

                // Remove the current bar from the stack
                st.pop();

                // Find the previous smaller bar's index
                int left = st.empty() ? -1 : st.top();

                // Calculate the width between the smaller boundaries
                int width = i - left - 1;

                // Calculate the rectangle area
                int area = height * width;

                // Update the maximum rectangle area
                maxArea = max(maxArea, area);
            }

            // Push the current index if it belongs to the original array
            if (i < n) {
                st.push(i);
            }
        }

        // Return the largest rectangle area
        return maxArea;
    }
};