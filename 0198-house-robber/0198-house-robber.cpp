class Solution {
public:
    int rob(vector<int>& nums) {
        // Maximum money robbed up to the previous house
        int prev1 = 0;

        // Maximum money robbed up to the house before previous
        int prev2 = 0;

        for (int money : nums) {
            // Either skip current house or rob it
            int curr = max(prev1, prev2 + money);

            // Move to the next house
            prev2 = prev1;
            prev1 = curr;
        }

        // Return maximum money that can be robbed
        return prev1;
    }
};