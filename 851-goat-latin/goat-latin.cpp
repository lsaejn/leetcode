// A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
//
// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
//
// The rules of Goat Latin are as follows:
//
//
// 	If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
// 	For example, the word 'apple' becomes 'applema'.
// 	 
// 	If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
// 	For example, the word "goat" becomes "oatgma".
// 	 
// 	Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// 	For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
//
//
// Return the final sentence representing the conversion from S to Goat Latin. 
//
//  
//
// Example 1:
//
//
// Input: "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
//
//
// Example 2:
//
//
// Input: "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
//
//
//  
//
// Notes:
//
//
// 	S contains only uppercase, lowercase and spaces. Exactly one space between each word.
// 	1 <= S.length <= 150.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string toGoatLatin(string S) {
        int begin=0;
        int pos=S.find_first_of(" ");
        string result;
        int count=1;
        while(pos!=string::npos)
        {
            string word=S.substr(begin,pos-begin);
            if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u'||word[0]=='A'||word[0]=='E'||word[0]=='I'||word[0]=='O'||word[0]=='U')
            {
                word+="ma";
            }
            else{//goat
                word+=word[0];
                word.erase(word.begin());
                word+="ma";
            }
            for(int i=count++;i!=0;--i)
                word+='a';
            result+=word;            
            result+=" ";
            begin=pos+1;
            pos=S.find_first_of(" ",begin);
        }

        auto word=S.substr(begin);
 if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u'||word[0]=='A'||word[0]=='E'||word[0]=='I'||word[0]=='O'||word[0]=='U')
            word+="ma";
        else{//goat
                word+=word[0];
                word.erase(word.begin());
                word+="ma";
            }
        for(int i=count;i!=0;--i)
          word+='a';
        
        return result+word;
    }
};
