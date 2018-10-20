// There are N children standing in a line. Each child is assigned a rating value.
//
// You are giving candies to these children subjected to the following requirements:
//
//
// 	Each child must have at least one candy.
// 	Children with a higher rating get more candies than their neighbors.
//
//
// What is the minimum candies you must give?
//
// Example 1:
//
//
// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//
//
// Example 2:
//
//
// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //如果找到波峰，那么我们向两边计算到波谷的长度，那么较长的那个就是所求
    // Candies for a slope of n elements
    int slope(int n)
    {
        return (n*(n+1))/2;
    }

    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1)  return ratings.size();
        int tot = 0;        // The final amount of candies
        int up = 0;         // Lenght of the last ascending slope
        int down = 0;       // Lenght of the last descending slope
        int oldsign = 0;    // Previous ratings trend (1 = ascending, -1 == descending, 0 = stable) 

        for (int i = 1; i< ratings.size(); i++)
        {
                        // Current ratings trend, same meaning as oldsign
            int newsign = ratings[i] > ratings[i-1] ? 1 : 
                          ratings[i] < ratings[i-1] ? -1 : 0;
                        // We can calculate the contribution of a slope 
                        // when that slope ends and it's not the peak of a mountain,
                        // that's why we have "newsign == 0" and not "newsign <= 0"
            if ((oldsign > 0 && newsign == 0)  ||
                (oldsign < 0  && newsign >= 0) )
                {
                        // The peak of the mountain should have max(up,down)+1
                        // candies, but the end of the mountain is the beginning of
                        // the next sequence, so we don't the candy at the end of 
                        // the mountain
                    tot += slope(up) + slope(down) + std::max(up, down);
                    up = 0;
                    down = 0;
                }

            if(newsign > 0)
                up++;
            if(newsign < 0)
                down++;
                    // Same rating of the previous child?
                    // Take one candy.If you are better then the next child
                    // the descending slope will take that into account, don't worry
            if(newsign == 0)
                tot++;
                
            oldsign = newsign;
        }
        
                    // Final sequence has to be closed
                    // Why +1? Because we don't have a sequence next!
        tot += slope(up) + slope(down) + std::max(up, down) + 1;
        return tot;
    }
};
