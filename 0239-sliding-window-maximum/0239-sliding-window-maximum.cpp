class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Deque stores indices
        deque<int> dq;

        // Stores maximum elements of each window
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Step 1: Remove indices outside the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2: Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Step 3: Insert current index
            dq.push_back(i);

            // Step 4: Store maximum after the first window is formed
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};