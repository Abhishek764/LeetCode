
class Solution {
public:
    int magicalString(int n) {

        // Handle the smallest input.
        if (n <= 3) {
            return n == 0 ? 0 : 1;
        }

        // First three characters of the magical string.
        vector<int> s = {1, 2, 2};

        // Count the number of 1s in the string.
        int count = 1;

        // i reads the size of the next group.
        int i = 2;

        // Next number to append.
        int num = 1;

        while (s.size() < n) {

            // Read how many times the current number
            // should be repeated.
            int freq = s[i];

            // Generate the next group.
            for (int j = 0; j < freq && s.size() < n; j++) {

                // Append the current number.
                s.push_back(num);

                // Count 1s as we generate the string.
                if (num == 1) {
                    count++;
                }
            }

            // Move to the next group size.
            i++;

            // Alternate between 1 and 2.
            num = 3 - num;
        }

        return count;
    }
};
