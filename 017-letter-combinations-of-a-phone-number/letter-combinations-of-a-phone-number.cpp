// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty()) return {};
        vector<string> result;
        result=letterCombinations(digits,0);
        return result;       
    }
    // a
     vector<string> letterCombinations(string& digits,int index)//构建从index~digit.size()-1
    {
         if(index>=digits.size()) return {};
         auto str=col[string()+digits[index]];//"abc"         
         vector<string> result;
         for(int i=0;i!=str.size();++i)
         {
            string re;
            auto vec=letterCombinations(digits,index+1);
            if(vec.empty())
                result.push_back(string()+str[i]);
            else
            {
                 for(auto & elem:vec)
                {
                    auto temp=string()+str[i]+elem;
                    result.push_back(temp);
                }
            }           
         }
         return result;           
    }
    
    
private:
    unordered_map<string,string> col={{"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"}};
};
