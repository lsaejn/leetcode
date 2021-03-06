// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//  
//
// Example 1:
//
//
// Input: 1
// Output: "1"
//
//
// Example 2:
//
//
// Input: 4
// Output: "1211"
//


class Solution {
public:
    //题目有点晕，但最终是递归。搜了一下，居然有非递归版本，但是没有看懂。
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
            
        string lastResult=countAndSay(n-1);
        string result;
        
        char lastchar=lastResult[0];
        int count=1;
        
        for(int i=1;i!=lastResult.size();++i)
        {
            if(lastResult[i]!=lastchar)
            {
                 result+=to_string(count);
                result.push_back(lastchar);
                lastchar=lastResult[i];
                count=1;
            }
            else
            {
                count++;
            }
            if(i==lastResult.size()-1)
            {
                result+=to_string(count);
                result.push_back(lastchar);
                count=0;
                return result;
            }
                          
        }
        return result;
        
    }
    
    
};
