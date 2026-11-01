
// class Solution {
// public:
//     bool checkPerfectNumber(int num) {
//         int original = num;
//         int sum = 0;

//         // Step 1: Check every number from 1 to num - 1.
//         for (int i = 1; i < num; i++) {

//             // Step 2: Check if i is a divisor of num.
//             if (num % i == 0) {

//                 // Step 3: Add the divisor to sum.
//                 sum += i;
//             }
//         }

//         // Step 4: Compare divisor sum with original number.
//         return sum == original;
//     }
// };













class Solution {
public:
    bool checkPerfectNumber(int num) {

        int original = num;
        // CORRECT: Save the original number.

        int sum = 0;
        // CORRECT: Store the sum of all proper divisors.

        for (int i = 1; i < num; i++) {

            // YOUR MISTAKE:
            // int divisor = 1;
            // This resets divisor to 1 in every iteration.
            // We don't need a separate divisor variable.
            
            // YOUR MISTAKE:
            // num
            // This is an incomplete statement.
            // We need to check whether i divides num.

            if (num % i == 0) {
                // CORRECT: If remainder is 0, i is a divisor.

                sum += i;
                // YOUR MISTAKE:
                // You added divisor in your while loop.
                // Instead, add i here because i is the divisor.
            }
        }

        // YOUR MISTAKE:
        // while (n > 0)
        // n is not declared.
        // Digit extraction is not needed for this problem.

        // YOUR MISTAKE:
        // int digit = n % 10;
        // This extracts digits, not divisors.

        // YOUR MISTAKE:
        // sum += divisor;
        // divisor is not available outside the for loop.

        // YOUR MISTAKE:
        // n /= 10;
        // This removes digits, which we don't need here.

        // CORRECT: Compare divisor sum with original number.
        return sum == original;
    }
};

