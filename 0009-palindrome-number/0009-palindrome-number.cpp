class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        // WRONG: rev * 10 can exceed the INT_MAX limit.
            // This causes signed integer overflow.
        // int rev = 0;
        long long rev = 0;
        while(x>0){
            int digit = x %10;

            rev = rev * 10 +digit;
            x /= 10;

        }

        return rev == original;
        
    }
};