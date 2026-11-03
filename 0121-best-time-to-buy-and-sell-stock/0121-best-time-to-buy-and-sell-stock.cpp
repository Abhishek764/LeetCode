class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Track the minimum price seen so far
        int minPrice = INT_MAX;

        // Store the maximum profit possible
        int maxProfit = 0;

        for (int price : prices) {

            // Update the minimum buying price
            minPrice = min(minPrice, price);

            // Calculate profit if we sell at the current price
            int profit = price - minPrice;

            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }

        // Return the maximum profit
        return maxProfit;
    }
};