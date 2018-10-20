// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
//
// Please note that the string does not contain any non-printable characters.
//
// Example:
//
// Input: "Hello, my name is John"
// Output: 5
//
//


#include <sstream>
class Solution {
public:
    int countSegments(string s) {
        istringstream istr(s);
        string str;
        int count=0;
        while(istr>>str)
        {
            ++count;
        }
        return count;
    }
};
