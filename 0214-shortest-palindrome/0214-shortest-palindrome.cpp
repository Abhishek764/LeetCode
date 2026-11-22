class Solution {
public:
    string shortestPalindrome(string s) {

        // Reverse the original string.
        string rev = s;
        reverse(rev.begin(), rev.end());

        long long base = 31;
        long long mod = 1e9 + 7;

        long long hash1 = 0;
        long long hash2 = 0;
        long long power = 1;

        int longest = 0;

        // Find the longest palindromic prefix using rolling hash.
        for (int i = 0; i < s.size(); i++) {

            // Hash of the original prefix.
            hash1 = (hash1 * base + (s[i] - 'a' + 1)) % mod;

            // Hash of the corresponding reversed prefix.
            hash2 = (hash2 + (s[i] - 'a' + 1) * power) % mod;

            power = (power * base) % mod;

            // Matching hashes indicate a palindromic prefix.
            if (hash1 == hash2) {
                longest = i + 1;
            }
        }

        // Add the remaining reversed characters in front.
        return rev.substr(0, s.size() - longest) + s;
    }
};