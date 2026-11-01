
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int original = num;
        int sum = 0;

        // Step 1: Check every number from 1 to num - 1.
        for (int i = 1; i < num; i++) {

            // Step 2: Check if i is a divisor of num.
            if (num % i == 0) {

                // Step 3: Add the divisor to sum.
                sum += i;
            }
        }

        // Step 4: Compare divisor sum with original number.
        return sum == original;
    }
};
