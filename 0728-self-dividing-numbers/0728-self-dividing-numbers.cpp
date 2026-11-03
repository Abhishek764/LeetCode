class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> ans;

        // Check every number in the given range
        for (int i = left; i <= right; i++) {

            int num = i;
            bool isSelfDividing = true;

            // Extract each digit
            while (num > 0) {

                int digit = num % 10;

                // Zero is not allowed
                if (digit == 0 || i % digit != 0) {
                    isSelfDividing = false;
                    break;
                }

                // Remove the last digit
                num = num / 10;
            }

            // Add valid numbers to the answer
            if (isSelfDividing) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};