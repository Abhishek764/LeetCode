class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        // i points to the first half of the array
        int i = 0;

        // j points to the second half of the array
        int j = n;

        // Store the shuffled elements
        vector<int> result;

        // Continue until all n pairs are processed
        while (i < n) {

            // Take an element from the first half (x)
            result.push_back(nums[i]);

            // Take the corresponding element from the second half (y)
            result.push_back(nums[j]);

            // Move both pointers to the next elements
            i++;
            j++;
        }

        // Return the shuffled array
        return result;
    }
};