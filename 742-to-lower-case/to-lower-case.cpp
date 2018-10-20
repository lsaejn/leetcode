// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
//
//  
//
//
// Example 1:
//
//
// Input: "Hello"
// Output: "hello"
//
//
//
// Example 2:
//
//
// Input: "here"
// Output: "here"
//
//
//
// Example 3:
//
//
// Input: "LOVELY"
// Output: "lovely"
//
//
//
//
//


class Solution {
public:
    string toLowerCase(string str) {
        /*
        char* lpstr=const_cast<char*>(str.c_str());
        while(*lpstr)
        {
            auto& c=*lpstr;
            if (c >= 'A' && c <= 'Z')
                c='a'-'A'+ c;
            ++lpstr;
        }
        return str;
        */
        std::transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
    }
};
