class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Store elements in the current window.
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            // Duplicate found within distance k.
            if (window.count(nums[i])) {
                return true;
            }

            // Add current element to the window.
            window.insert(nums[i]);

            // Maintain window size of at most k.
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};