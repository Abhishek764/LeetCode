class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Step 1: Get the size of the array
        int n = nums.size();

        // Store all missing numbers
        vector<int> ans;

        // Step 2: Traverse the array
        for (int i = 0; i < n; i++) {

            // Step 3: Find the index corresponding to the number
            int index = abs(nums[i]) - 1;

            // Step 4: Mark the index as negative
            // Negative means this number is present
            nums[index] = -abs(nums[index]);
        }

        // Step 5: Traverse the array again
        for (int i = 0; i < n; i++) {

            // Step 6: Positive value means the number is missing
            if (nums[i] > 0) {

                // Step 7: Convert index back to its number
                ans.push_back(i + 1);
            }
        }

        // Step 8: Return all missing numbers
        return ans;
    }
};