class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // Step 1: Get the size of the array
        int n = nums.size();

        // Step 2: Create an answer array
        vector<int> ans(n, 0);

        // Step 3: Select each element one by one
        for (int i = 0; i < n; i++) {

            // Step 4: Compare it with every other element
            for (int j = 0; j < n; j++) {

                // Step 5: Count elements smaller than nums[i]
                if (nums[j] < nums[i]) {
                    ans[i]++;
                }
            }
        }

        // Step 6: Return the result
        return ans;
    }
};