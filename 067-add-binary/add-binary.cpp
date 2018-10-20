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
//


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
