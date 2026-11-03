class Solution {
public:
    int countDigitOne(int n) {

        long long count = 0;

        // Check every digit position: ones, tens, hundreds, etc.
        for (long long factor = 1; factor <= n; factor *= 10) {

            long long divisor = factor * 10;

            // Count complete cycles of 1s
            count += (n / divisor) * factor;

            // Count remaining 1s at the current position
            count += min(max(n % divisor - factor + 1, 0LL), factor);
        }

        return count;
    }
};