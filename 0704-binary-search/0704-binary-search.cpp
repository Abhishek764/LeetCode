class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        /*
            Binary Search:
            Since the array is sorted, we can eliminate
            half of the search space in every iteration.
        */
        while (left <= right) {

            // Find the middle index safely.
            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target) {
                return mid;
            }

            // Target is greater, search the right half.
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            // Target is smaller, search the left half.
            else {
                right = mid - 1;
            }
        }

        // Target does not exist in the array.
        return -1;
    }
};

/*
    Example:
    nums = [-1, 0, 3, 5, 9, 12]
    target = 9

    left = 0, right = 5
    mid = 2
    nums[2] = 3

    3 < 9
    Search right half.

    left = 3, right = 5
    mid = 4
    nums[4] = 9

    Target found!

    Answer = 4

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

/*
    If this solution helped you, please consider giving
    it an ⬆️ Upvote!

    Happy Coding! 🚀
*/