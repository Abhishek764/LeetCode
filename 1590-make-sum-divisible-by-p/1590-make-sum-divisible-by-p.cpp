class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        // Step 1: Calculate the remainder of the total sum.
        // We use modulo at every step to avoid integer overflow.
        long long totalRemainder = 0;

        for (int num : nums) {
            totalRemainder = (totalRemainder + num) % p;
        }

        // Step 2: If the total sum is already divisible by p,
        // no subarray needs to be removed.
        if (totalRemainder == 0) {
            return 0;
        }

        // Step 3: Create a hash map to store:
        // prefix remainder -> latest index.
        unordered_map<long long, int> mp;

        // An empty prefix has remainder 0 at index -1.
        mp[0] = -1;

        long long prefixRemainder = 0;
        int minLength = nums.size();

        // Step 4: Traverse the array and calculate prefix remainders.
        for (int i = 0; i < nums.size(); i++) {

            prefixRemainder = (prefixRemainder + nums[i]) % p;

            // Step 5: Find the remainder needed to remove
            // so that the remaining sum becomes divisible by p.
            long long target = (prefixRemainder - totalRemainder + p) % p;

            // Step 6: If this remainder exists, we found
            // a subarray whose sum has the required remainder.
            if (mp.find(target) != mp.end()) {

                // Calculate the length of this subarray.
                minLength = min(minLength, i - mp[target]);
            }

            // Step 7: Store the current remainder and index.
            // Keeping the latest index helps find the shortest subarray.
            mp[prefixRemainder] = i;
        }

        // Step 8: The entire array cannot be removed.
        // Return -1 if no valid shorter subarray exists.
        return minLength == nums.size() ? -1 : minLength;
    }
};