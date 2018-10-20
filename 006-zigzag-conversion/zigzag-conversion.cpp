// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    //我没有时间总结规律http://www.cnblogs.com/springfor/p/3889414.html
    //直接准备3个桶，从上向下放元素，到底了再向上放，也得也很快
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        vector<string> vec(numRows);
        int direction=1;//1向下，-1向上
        for(int i=0,j=0;i!=s.size();++i)
        {
            vec[j].push_back(s[i]);
            if(1==direction)
            {             
              if(j==numRows-1)
              {
                  direction=-1;
                  j--;
                  continue;
              }
                else
                    j++;
            }
            if(-1==direction)
            {             
              if(j==0)
              {
                  direction=1;
                  j++;
              }
                else
                    j--;
            }                      
        }
        string result;
        for(auto iter=vec.begin();iter!=vec.end();++iter)
            result+=*iter;
        return result;
        
    }
};

