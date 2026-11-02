
class Solution {
public:
    int pivotInteger(int n) {

        // Step 1: Try every number as a possible pivot.
        for (int x = 1; x <= n; x++) {

            int leftSum = 0;
            int rightSum = 0;

            // Step 2: Calculate sum from 1 to x.
            for (int i = 1; i <= x; i++) {
                leftSum += i;
            }

            // Step 3: Calculate sum from x to n.
            for (int i = x; i <= n; i++) {
                rightSum += i;
            }

            // Step 4: Compare both sums.
            if (leftSum == rightSum) {
                return x;
            }
        }

        // Step 5: No pivot integer found.
        return -1;
    }
};
