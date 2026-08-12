class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        // Intuition: only nums[right] itself can break the window, shrink from left until it fits again
        int n = nums.size();
        int r = 1;
        int left = 0;
        std::unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            int c = nums[right];
            freq[c]++;
            // Decrease window length until k constraint is true again
            while (freq[c] > k) {
                int d = nums[left];
                freq[d]--;
                left++;
            }
            r = std::max(r, right - left + 1);
        }
        return r;
    }
};