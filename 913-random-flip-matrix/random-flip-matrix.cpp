// You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space complexity.
//
// Note:
//
//
// 	1 <= n_rows, n_cols <= 10000
// 	0 <= row.id < n_rows and 0 <= col.id < n_cols
// 	flip will not be called when the matrix has no 0 values left.
// 	the total number of calls to flip and reset will not exceed 1000.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","flip","flip","flip","flip"]
// [[2,3],[],[],[],[]]
// Output: [null,[0,1],[1,2],[1,0],[1,1]]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","flip","flip","reset","flip"]
// [[1,2],[],[],[],[]]
// Output: [null,[0,0],[0,1],null,[0,0]]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, n_rows and n_cols. flip and reset have no arguments. Arguments are always wrapped with a list, even if there aren't any.
//


class Solution {
public:
    /*
    So, the steps are:

generate random from 0 to n : m
swap m and n
decrease n
*/
    
    Solution(int n_rows, int n_cols) {
        
        m = n_rows;
        n = n_cols;
        reset();
    }
    
    
    //这其实是muduo的一个优化，删除一个元素并不是真的删除掉，
    //而是将它和最后一个元素交换，然后size--，那这个元素的真实值是什么呢？用hash来记录
    //比如现在4个元素,1,2,3,4，你要删除2，真的删除吗？那下一次随机到2怎么办呢？
    //可以这么做:保留2，但是它的实际元素是第最后一个元素。hash[2]=4
    //
    vector<int> flip() {
        
        int k = rand() % (index + 1);//得到一个待删除索引
        int val = k;
        if (hash.count(k) != 0) //如果表里有k,比如你连续随机出两个2，那么你实际是删除了2，4，
            val = hash[k];      //重置val，返回它取代的那个元素                         
         //表里没有k

        if (hash.count(index) == 0) //最大的索引没有被使用
            hash[k] = index;        //因为表里没有找到2，我们删除2，并让2代表4.所以下一次删除2应该通过查表转到index，将hash(2)=4放入表里
        else 
               hash[k] = hash[index];//否则
        --index;
        
        return {val / n, val % n};
    }
    
    void reset() {
        
        index = m * n - 1;        
        hash.clear();        
    }
    
    int m;
    int n;
    unordered_map<int, int> hash;//这个表是什么呢？是index
    int index;
};
