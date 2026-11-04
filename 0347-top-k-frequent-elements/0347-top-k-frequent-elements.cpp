class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets based on frequency
        vector<vector<int>> buckets(nums.size() + 1);

        // Step 3: Place elements into their frequency buckets
        for (auto it : freq) {
            buckets[it.second].push_back(it.first);
        }

        // Step 4: Collect k most frequent elements
        vector<int> ans;

        for (int i = buckets.size() - 1; i >= 0; i--) {

            for (int num : buckets[i]) {

                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};