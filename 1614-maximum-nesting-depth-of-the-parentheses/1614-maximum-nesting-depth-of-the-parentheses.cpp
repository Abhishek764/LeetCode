class Solution {
public:
    int maxDepth(string s) {
        int x = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                x++;

                if (x > ans) {
                    ans = x;
                }
            }
            else if (s[i] == ')') {
                x--;
            }
        }

        return ans;
    }
};