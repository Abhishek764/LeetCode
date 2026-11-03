class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> ans;

        // Generate all 2^n Gray code numbers
        for (int i = 0; i < (1 << n); i++) {

            // Convert binary number to Gray code
            int gray = i ^ (i >> 1);

            // Store the Gray code
            ans.push_back(gray);
        }

        return ans;
    }
};