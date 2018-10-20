// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string addBinary(string a, string b) {
        //若转换成整形，则偏离题意
        char pro='0';
        if(a.size()<b.size())
            std::swap(a,b);
        string result;
        int i=a.size()-1;int j=b.size()-1;
        for(;i>=0;--i,--j)
        {
            if(j>=0)
            {
                result.push_back(add(a[i],b[j],pro));                
            }      
            else
            result.push_back(add(a[i],'0',pro));
        }
        if(pro=='1')
           result.push_back('1'); 
        reverse(result.begin(),result.end());
       // auto pos=std::find_first_not_of(result.begin(),result.end(),'0');
        auto pos=result.find_first_not_of('0');
        if(pos==string::npos)
            return "0";
        return result.substr(pos);        
    }
    
    
    
    char add(char a,char b,char& pro){
        if(pro=='0')
        {
            if(a=='0'&&b=='0')
            {
                pro='0';
                return '0';
            }
           
            else if(a=='1'&&b=='1')
            {
                pro='1';
                return '0';
            }                
            else
            {
                pro='0';
                return '1';
            }
                
        }
        else if(pro=='1')
        {
            if(a=='0'&&b=='0')
            {
                pro='0';
               return '1'; 
            }
            
            if(a=='1'&&b=='1')
            {
                pro='1';
                return '1';
            }                
            else
            {
                pro='1';
               return '0'; 
            }
                
        }

            
            
    } 
};
