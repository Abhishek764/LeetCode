// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();

//         for(int i = 0;i<n-1;i++){
//             for(int j = i+1;j< n; j++){
//                 if(nums[i] + nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
        
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Step 1: Create a hash map to store:
        // number -> its index.
        unordered_map<int, int> mp;

        // Step 2: Traverse the array once.
        for (int i = 0; i < nums.size(); i++) {

            // Step 3: Calculate the number needed to reach target.
            int complement = target - nums[i];

            // Step 4: Check if the complement already exists.
            if (mp.find(complement) != mp.end()) {

                // If found, return the indices of both numbers.
                return {mp[complement], i};
            }

            // Step 5: Store the current number and its index.
            // Store it after checking to avoid using the same element twice.
            mp[nums[i]] = i;
        }

        // Step 6: Return empty if no pair is found.
        return {};
    }
};