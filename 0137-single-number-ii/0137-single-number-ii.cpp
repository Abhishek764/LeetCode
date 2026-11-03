class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Store bits that have appeared once
        int ones = 0;

        // Store bits that have appeared twice
        int twos = 0;

        for (int num : nums) {

            // Update bits appearing once and remove bits already in twos
            ones = (ones ^ num) & ~twos;

            // Update bits appearing twice and remove bits now in ones
            twos = (twos ^ num) & ~ones;
        }

        // Return the number that appeared only once
        return ones;
    }
};