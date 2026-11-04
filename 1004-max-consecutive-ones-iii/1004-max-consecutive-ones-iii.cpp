class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int maxLength = 0;

        // Expand the window using right pointer
        for (int right = 0; right < nums.size(); right++) {

            // Count zeros in the current window
            if (nums[right] == 0) {
                zeros++;
            }

            // Shrink the window if zeros exceed k
            while (zeros > k) {

                if (nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            // Update maximum valid window length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};