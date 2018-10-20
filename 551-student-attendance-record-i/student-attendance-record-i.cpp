// You are given a string representing an attendance record for a student. The record only contains the following three characters:
//
//
//
// 'A' : Absent. 
// 'L' : Late.
//  'P' : Present. 
//
//
//
//
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).    
//
// You need to return whether the student could be rewarded according to his attendance record.
//
// Example 1:
//
// Input: "PPALLP"
// Output: True
//
//
//
// Example 2:
//
// Input: "PPALLL"
// Output: False
//
//
//
//
//


class Solution {
public:
    //查找子串A和LLL即可
    bool checkRecord(string s)
    {
                return (s.find("A") == string::npos || s.find("A") == s.rfind("A")) && s.find("LLL") == string::npos;
    }
};
