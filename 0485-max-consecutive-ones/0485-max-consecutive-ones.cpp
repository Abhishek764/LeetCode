class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        // Step 1: Track the current consecutive 1s
        int count = 0;

        // Step 2: Store the maximum consecutive 1s
        int maxCount = 0;

        // Step 3: Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {

            // Step 4: If the current element is 1
            if (nums[i] == 1) {

                // Increase the consecutive count
                count++;

                // Update the maximum count
                maxCount = max(maxCount, count);

            } 
            else {

                // Step 5: Reset count when 0 is encountered
                count = 0;
            }
        }

        // Step 6: Return the maximum consecutive 1s
        return maxCount;
    }
};