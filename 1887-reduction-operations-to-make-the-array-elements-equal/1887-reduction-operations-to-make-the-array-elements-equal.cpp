class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        /*
            Step 1: Sort the array in ascending order.

            After sorting, equal elements will be together.
            We can process elements from right to left,
            starting with the largest value.
        */
        sort(nums.begin(), nums.end());

        int operations = 0;

        /*
            Step 2: Count how many distinct larger levels exist.

            Whenever nums[i] != nums[i - 1], we find a new
            smaller value.

            Every element in the larger group needs one
            additional operation to reach this smaller level.
        */
        for (int i = nums.size() - 1; i > 0; i--) {

            if (nums[i] != nums[i - 1]) {

                // All elements from index i to the end
                // must be reduced one more time.
                operations += nums.size() - i;
            }
        }

        return operations;
    }
};

/*
    Example:
    nums = [1, 1, 2, 2, 3]

    Sorted array = [1, 1, 2, 2, 3]

    i = 4: 3 != 2
           operations += 5 - 4 = 1

    i = 3: 2 != 2
           No operation added.

    i = 2: 2 != 1
           operations += 5 - 2 = 3

    Total operations = 1 + 3 = 4

    Time Complexity: O(n log n)
        Sorting takes O(n log n).
        Traversing the array takes O(n).

    Space Complexity: O(1) auxiliary space
        Ignoring the sorting implementation.
*/