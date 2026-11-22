class Solution {
public:
    long long sumScores(string s) {

        int n = s.size();

        vector<int> z(n, 0);

        int left = 0, right = 0;

        long long ans = n;

        for (int i = 1; i < n; i++) {

            // Reuse previously calculated prefix matches.
            if (i <= right) {
                z[i] = min(right - i + 1, z[i - left]);
            }

            // Extend the matching prefix.
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            // Update the current matching window.
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }

            // Add the longest common prefix length.
            ans += z[i];
        }

        return ans;
    }
};