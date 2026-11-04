class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Track maximum and minimum product ending at current index
        int maxProd = nums[0];
        int minProd = nums[0];

        // Store the overall maximum product
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // A negative number can turn minimum into maximum
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            // Either start a new subarray or extend the previous one
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            // Update the overall maximum product
            ans = max(ans, maxProd);
        }

        return ans;
    }
};