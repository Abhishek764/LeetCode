class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        // Step 1: Calculate the total sum of even and odd indices.
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                evenSum += nums[i];
            } else {
                oddSum += nums[i];
            }
        }

        // Step 2: Maintain prefix sums while traversing the array.
        int leftEven = 0;
        int leftOdd = 0;

        int count = 0;

        // Step 3: Try removing each index one by one.
        for (int i = 0; i < nums.size(); i++) {

            // Step 4: Calculate the sums on the right side
            // after excluding the current element.
            int rightEven = evenSum - leftEven;
            int rightOdd = oddSum - leftOdd;

            // Step 5: Remove the current element from its original parity.
            if (i % 2 == 0) {
                rightEven -= nums[i];
            } else {
                rightOdd -= nums[i];
            }

            // Step 6: After removal, right-side indices change parity.
            // Therefore, even and odd sums on the right get swapped.
            int newEvenSum = leftEven + rightOdd;
            int newOddSum = leftOdd + rightEven;

            // Step 7: Check whether the new even and odd sums are equal.
            if (newEvenSum == newOddSum) {
                count++;
            }

            // Step 8: Add the current element to its original
            // left-side prefix sum before checking the next index.
            if (i % 2 == 0) {
                leftEven += nums[i];
            } else {
                leftOdd += nums[i];
            }
        }

        // Step 9: Return the number of valid indices.
        return count;
    }
};