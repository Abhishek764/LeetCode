using ll = long long;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the absolute boundaries of the progression
        int maxm = *max_element(arr.begin(), arr.end());
        int minm = *min_element(arr.begin(), arr.end());
        
        // Step 2: Calculate the expected step size
        int diff = (maxm - minm) / (n - 1);
        
        // If the difference doesn't divide evenly, an AP is impossible
        // (Integer division truncates, making this check fail if there was a remainder)
        if (minm + diff * (n - 1) != maxm) {
            return false;
        }
        
        // Step 3: Throw all numbers into a Hash Set for O(1) lookups
        unordered_set<int> s(arr.begin(), arr.end());
        
        // Step 4: Verify every expected term of the sequence exists in the set
        for (int i = 1; i < n; i++) {
            if (s.find(minm + i * diff) == s.end()) {
                return false;
            }
        }
        
        return true;
    }
};