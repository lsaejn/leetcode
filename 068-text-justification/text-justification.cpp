// Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is inserted between words.
//
// Note:
//
//
// 	A word is defined as a character sequence consisting of non-space characters only.
// 	Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// 	The input array words contains at least one word.
//
//
// Example 1:
//
//
// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
//
//
// Example 2:
//
//
// Input:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be",
//              because the last line must be left-justified instead of fully-justified.
//              Note that the second line is also left-justified becase it contains only one word.
//
//
// Example 3:
//
//
// Input:
// words = ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
//
//


class Solution {
public:
    //这是要写office吗。。。
    //我们先统计每行应该放的单词数，然后排版。
    //这样可以将工作划分成两个
    vector<string> fullJustify(vector<string> &words, int L) 
    {
        vector<string> res;
        int k=0;
        int l=0;//l，计算当前行能放的字符串个数
        for(int i = 0; i < words.size(); i += k) //前进k个字符
        {
            k=0; l=0;
            for(;i + k < words.size() ; k++) 
            {
                if(l + words[i+k].size()+k > L)//已有长度+想放的单词长度+空格数>超过长度
                    break;
                l += words[i+k].size();
            }
            string tmp = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) tmp += " ";
                else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i+j+1];
            }
            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};
