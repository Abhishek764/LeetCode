class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};

// class Solution {
// public:
//     bool isPalindrome(string& s) {

//         // Step 1: Two pointers
//         int left = 0;
//         int right = s.size() - 1;

//         // Step 2: Compare characters from both ends
//         for (; left < right; ) {

//             // Step 3: Skip spaces and special characters from left
//             while (left < right && !isalnum((unsigned char)s[left])) {
//                 left++;
//             }

//             // Step 4: Skip spaces and special characters from right
//             while (left < right && !isalnum((unsigned char)s[right])) {
//                 right--;
//             }

//             // Step 5: Convert both characters to lowercase
//             // Then compare them
//             if (tolower((unsigned char)s[left]) !=
//                 tolower((unsigned char)s[right])) {
//                 return false;
//             }

//             // Step 6: Move both pointers
//             left++;
//             right--;
//         }

//         // Step 7: All characters matched
//         return true;
//     }
// };