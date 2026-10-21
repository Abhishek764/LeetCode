#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        return s;
    }
};