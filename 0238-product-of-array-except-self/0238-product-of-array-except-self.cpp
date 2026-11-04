class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Initialize the answer array with 1
        vector<int> ans(n, 1);

        // Step 2: Calculate prefix products
        // ans[i] stores the product of all elements before index i
        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Step 3: Calculate suffix products
        // Multiply each position by the product of all elements after it
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        // Step 4: Return the final product array
        return ans;
    }
};