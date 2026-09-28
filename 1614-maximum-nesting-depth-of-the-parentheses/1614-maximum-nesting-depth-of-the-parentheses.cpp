class Solution {
public:
    int maxDepth(string s) {
        int x = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                x++;
                ans = max(ans, x);
            }
            else if (c == ')') {
                x--;
            }
        }

        return ans;
    }
};