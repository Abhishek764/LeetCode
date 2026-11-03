class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // A number ending in 1 cannot be divisible by 2 or 5
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int remainder = 0;

        // Try numbers: 1, 11, 111, 1111...
        for (int length = 1; length <= k; length++) {

            // Append digit 1 without building the actual number
            remainder = (remainder * 10 + 1) % k;

            // If remainder is 0, the number is divisible by k
            if (remainder == 0) {
                return length;
            }
        }

        return -1;
    }
};