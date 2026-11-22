class Solution {
public:
    string longestPrefix(string s) {

        long long base = 31;
        long long mod = 1e9 + 7;

        long long hash1 = 0;
        long long hash2 = 0;
        long long power = 1;

        int longest = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {

            // Calculate prefix hash.
            hash1 = (hash1 * base + (s[i] - 'a' + 1)) % mod;

            // Calculate suffix hash from right to left.
            hash2 = (hash2 + (s[n - 1 - i] - 'a' + 1) * power) % mod;

            power = (power * base) % mod;

            // Check whether prefix and suffix hashes match.
            if (hash1 == hash2) {
                longest = i + 1;
            }
        }

        return s.substr(0, longest);
    }
};