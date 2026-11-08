class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        // Store original prices as the initial answer
        vector<int> ans = prices;

        // Store indices waiting for their discount
        stack<int> st;

        // Traverse prices from left to right
        for (int i = 0; i < prices.size(); i++) {

            // Check if current price is smaller than or equal
            // to the price at the top index of the stack
            while (!st.empty() && prices[st.top()] >= prices[i]) {

                // Get the index of the item receiving the discount
                int idx = st.top();

                // Remove the index because its discount is found
                st.pop();

                // Subtract the discount from the original price
                ans[idx] = prices[idx] - prices[i];
            }

            // Store current index for a future discount
            st.push(i);
        }

        // Return final discounted prices
        return ans;
    }
};