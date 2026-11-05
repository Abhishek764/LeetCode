class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Store left character temporarily
            char temp = s[left];

            // Put right character at left position
            s[left] = s[right];

            // Put old left character at right position
            s[right] = temp;

            // Move pointers
            left++;
            right--;
        }
    }
};