class Solution {
public:
    int minOperations(int n) {
        // Step 1: Initialize the operation counter
        int operations = 0;

        // Step 2: Continue until n becomes zero
        while (n > 0) {

            // Step 3: If n is even, divide by 2
            // This is a conceptual binary shift, not an operation
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                // Step 4: For 3 or numbers ending in binary 01,
                // subtract 1 to reduce the remaining set bits
                if (n == 3 || n % 4 == 1) {
                    n--;
                }
                // Step 5: Otherwise, add 1 to create a carry
                // and eliminate consecutive set bits
                else {
                    n++;
                }

                // Step 6: Count the actual operation
                operations++;
            }
        }

        // Step 7: Return the minimum number of operations
        return operations;
    }
};