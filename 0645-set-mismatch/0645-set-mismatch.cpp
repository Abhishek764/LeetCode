class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        // Step 1: Get the size of the array
        int n = nums.size();

        // Step 2: Create a frequency array
        vector<int> freq(n + 1, 0);

        // Step 3: Count the frequency of each number
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Variables to store duplicate and missing numbers
        int duplicate = 0;
        int missing = 0;

        // Step 4: Check numbers from 1 to n
        for (int i = 1; i <= n; i++) {

            // Number appearing twice is the duplicate
            if (freq[i] == 2) {
                duplicate = i;
            }

            // Number appearing zero times is missing
            if (freq[i] == 0) {
                missing = i;
            }
        }

        // Step 5: Return duplicate first, missing second
        return {duplicate, missing};
    }
};