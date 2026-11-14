class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left = 0;
        int right = arr.size() - 1;

        /*
            Binary Search:
            Find the point where the increasing slope
            changes into the decreasing slope.
        */
        while (left < right) {

            int mid = left + (right - left) / 2;

            /*
                If the next element is greater,
                we are on the increasing slope.

                So, the peak must be on the right side.
            */
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }

            /*
                Otherwise, we are at the peak
                or on the decreasing slope.

                So, the peak is at mid or to its left.
            */
            else {
                right = mid;
            }
        }

        // left and right meet at the peak index.
        return left;
    }
};

/*
    Example:
    arr = [0, 2, 1, 0]

    left = 0, right = 3
    mid = 1

    arr[1] = 2
    arr[2] = 1

    2 < 1? No
    right = mid = 1

    left = 0, right = 1
    mid = 0

    arr[0] = 0
    arr[1] = 2

    0 < 2? Yes
    left = mid + 1 = 1

    left == right

    Answer = 1

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/