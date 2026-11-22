class Solution {
public:
    string decodeString(string s) {

        int i = 0;

        return decode(s, i);
    }

    string decode(string& s, int& i) {

        string result = "";
        int num = 0;

        while (i < s.size() && s[i] != ']') {

            // Build the repetition number.
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // Decode the nested substring.
            else if (s[i] == '[') {
                i++;

                string temp = decode(s, i);

                // Repeat the decoded substring.
                while (num--) {
                    result += temp;
                }

                num = 0;
            }

            // Add normal characters.
            else {
                result += s[i];
            }

            i++;
        }

        return result;
    }
};