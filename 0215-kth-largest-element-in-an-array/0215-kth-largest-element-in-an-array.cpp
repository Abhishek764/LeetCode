class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // The kth largest element is at index n - k.
        return nums[nums.size() - k];
    }
};

/*
    Example:
    nums = [3, 2, 1, 5, 6, 4], k = 2

    Sorted array = [1, 2, 3, 4, 5, 6]

    Index = 6 - 2 = 4

    nums[4] = 5

    Answer = 5

    Time Complexity: O(n log n) - Sorting.
    Space Complexity: O(1) auxiliary space.
*/