// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
// Example:
//
//
// Input: 
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
//
// Output: ["eat","oath"]
//
//
// Note:
// You may assume that all inputs are consist of lowercase letters a-z." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这道题有难度，原因在于之前的 实施Trie 就没写好，Word search 查找用的是dfs，Add and Search Word用的是vector
    //结果就是这道题几乎要重头写。
    //提示给的很明显了.
    //1.将board写成哈希表，依单词序查字母，若周围无此字母，停止。若有，继续进行深度遍历。
    //2.实现所有单词的前缀树。对单词进行查询即可
    class Trie {
    public:
        //我们不知道性能要求，所以直接用容器代替
        struct TreeNode
        {
            TreeNode(char c=' '):charactor(c){};
            char charactor=' ';
            string str;
            map<char,TreeNode*> child;   
        };
        /** Initialize your data structure here. */
        Trie() {        
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            auto * copy=&root;
            for(int i=0;i!=word.size();++i)
            {
                if(copy->child.count(word[i]))
                    copy=copy->child[word[i]];
                else
                {
                    auto newChild=new TreeNode(word[i]);
                    copy->child[word[i]]=newChild;
                    copy=newChild;
                }
            }  
            copy->str=word;
        }         
        TreeNode root;
    };
     
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) 
    {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) 
            T.insert(a);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j) 
                if (T.root.child.count(board[i][j])>0) 
                    search(board, T.root.child[board[i][j]], i, j, visit, res);      
        return res;
    }
    
     //检查board(i,j)的四个方向和TrieNode p的子树的值是否相同
    void search(vector<vector<char> > &board, Trie::TreeNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) { 
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child.count(board[nx][ny])) {
                search(board, p->child[board[nx][ny]], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};
