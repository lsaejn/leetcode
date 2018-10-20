// Write a function that takes a string as input and reverse only the vowels of a string.
//
//
// Example 1:
// Given s = "hello", return "holle".
//
//
//
// Example 2:
// Given s = "leetcode", return "leotcede".
//
//
//
// Note:
// The vowels does not include the letter "y".
//



class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

