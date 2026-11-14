class Solution {
public:

    /*
        Merge two sorted parts of the array.

        First part:  [left ... mid]
        Second part: [mid + 1 ... right]
    */
    void merge(vector<int>& nums, int left, int mid, int right) {

        vector<int> temp;

        int i = left;
        int j = mid + 1;

        // Compare elements from both halves.
        // Insert the smaller element into temp.
        while (i <= mid && j <= right) {

            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Copy remaining elements from the left half.
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Copy remaining elements from the right half.
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy the merged sorted elements back.
        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    /*
        Divide the array into smaller halves
        and recursively sort them.
    */
    void mergeSort(vector<int>& nums, int left, int right) {

        // Base case: A single element is already sorted.
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        // Sort the left half.
        mergeSort(nums, left, mid);

        // Sort the right half.
        mergeSort(nums, mid + 1, right);

        // Merge both sorted halves.
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};

/*
    Example:
    nums = [5, 2, 3, 1]

    Divide:
    [5, 2]       [3, 1]
    [5] [2]      [3] [1]

    Merge:
    [2, 5]       [1, 3]

    Final Merge:
    [1, 2, 3, 5]

    Answer = [1, 2, 3, 5]

    Time Complexity: O(n log n)
    Space Complexity: O(n)
*/