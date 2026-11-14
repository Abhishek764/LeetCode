class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        // Step 1: Sort the array.
        // After sorting, the closest elements will be adjacent.
        sort(arr.begin(), arr.end());

        // Step 2: Find the minimum absolute difference.
        int minDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {

            // Since the array is sorted, subtraction is always non-negative.
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        // Step 3: Collect all pairs having the minimum difference.
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] - arr[i - 1] == minDiff) {

                // Store the smaller element first.
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};