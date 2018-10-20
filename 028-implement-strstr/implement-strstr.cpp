// Implement strStr().
//
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
//
//
// Input: haystack = "hello", needle = "ll"
// Output: 2
//
//
// Example 2:
//
//
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
//
//
// Clarification:
//
// What should we return when needle is an empty string? This is a great question to ask during an interview.
//
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//


class Solution {
public://我实在不屑于做这个
    int strStr(string haystack, string needle) {
        auto iter=haystack.find(needle);
        return iter==string::npos?-1:iter;
    }
};
/*
assert !needle.empty()
for(int i=0;i!=haystack.size();++i)
{
    int j=0;
    while(j<needle.size())
    {
        if(haystack[i+j]==needle[j])
        continue
        else
        break;
    
    }
    return i;
}
return false;


*/
