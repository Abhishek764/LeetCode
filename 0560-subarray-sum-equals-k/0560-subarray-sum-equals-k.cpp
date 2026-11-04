class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Step 1: Initialize prefix sum and answer count
        int sum = 0;
        int count = 0;

        // Step 2: Store prefix sum frequencies
        // Initially, sum 0 has occurred once
        unordered_map<int, int> mp;
        mp[0] = 1;

        // Step 3: Traverse the array
        for (int num : nums) {

            // Update the current prefix sum
            sum += num;

            // Step 4: Check if a previous prefix sum equals sum - k
            // If found, the subarray between those positions has sum k
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Step 5: Store the frequency of the current prefix sum
            mp[sum]++;
        }

        // Step 6: Return the total number of valid subarrays
        return count;
    }
};