// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
//
// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
//
// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
//
// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
//
// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.
//
// Note:
//
//
// 	Starting point is assumed to be valid, so it might not be included in the bank.
// 	If multiple mutations are needed, all mutations during in the sequence must be valid.
// 	You may assume start and end string is not the same.
//
//
//  
//
// Example 1:
//
//
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
//
// return: 1
//
//
//  
//
// Example 2:
//
//
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
//
// return: 2
//
//
//  
//
// Example 3:
//
//
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
//
// return: 3
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //简述一下流程，比如把例3 bank变为 ["AAAACCCC", "AAACCCCC", "AACCCCCC"，ACAAACCC，AAAAAACC]
    //首先end要在库里
    //AAAAACCC放入队列，将队列所有元素可以变化的元素重新放入队列，删除之前的元素，
    //AAAAACCC->AAAACCCC+ACAAACCC+AAAAAACC->AAACCCCC->AACCCCCC
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> toVisit;
        unordered_set<string> dict(bank.begin(), bank.end());//去掉重复
        int dist = 0;
 
        if(!dict.count(end)) return -1;
 
        toVisit.push(start);
        dict.insert(start); 
        while(!toVisit.empty())
        {
            int n = toVisit.size();
            for(int i=0; i<n; i++)//取出队列里所有要访问的
            {
                string str = toVisit.front();
                toVisit.pop();
                if(str==end) return dist;
                addWord(str, dict, toVisit);//将字符串str变化
            }
            dist++;//变化了一次
        }
        return -1;
 
    }
 
    void addWord(string word, unordered_set<string>& dict, queue<string>& toVisit) {
        dict.erase(word);
        for(int i=0; i<word.size(); i++)//修改字符串的每一位
        {
            char tmp = word[i];
            for(char c:string("ACGT"))//分别修改成ACGT
            {
                if( word[i] == c) continue;
                word[i] = c;
                if(dict.count(word))//dict有，说明可以变化
                {
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
};

