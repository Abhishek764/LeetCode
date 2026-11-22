class Solution {
public:
    char findKthBit(int n, int k) {

        // Base case: S1 = "0".
        if (n == 1) {
            return '0';
        }

        // Length of Sn is 2^n - 1.
        int mid = (1 << (n - 1));

        // Middle bit is always 1.
        if (k == mid) {
            return '1';
        }

        // First half remains unchanged.
        if (k < mid) {
            return findKthBit(n - 1, k);
        }

        // Second half is reversed and inverted.
        // Find the corresponding position in the first half.
        char bit = findKthBit(n - 1, (1 << n) - k);

        // Invert the returned bit.
        return bit == '0' ? '1' : '0';
    }
};