// Write a function that takes a string as input and returns the string reversed.
//
// Example 1:
//
//
//
// Input: "hello"
// Output: "olleh"
//
//
//
// Example 2:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: "amanaP :lanac a ,nalp a ,nam A"
//
//
//
//


class Solution {
public:
    //以为有陷阱，但是。。。没有陷阱也是一种陷阱。。。
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
        
    }
};
