// Find the largest palindrome made from the product of two n-digit numbers.
//  Since the result could be very large, you should return the largest palindrome mod 1337.
//
// Example:
// Input: 2
// Output: 987
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//
//
//
//
// Note:
// The range of n is [1,8].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //给我们一个数字n，问两个n位数的乘积组成的最大回文数是多少，返回的结果对1337取余
    //99*99 99*98 98*98 ...
    //这样不好
    //n位数的平方不超过2n位，n=2时，最大不超过是9999，9999=9900-99=9801，第一个回文是9779...然后9669，9559，9449，9339，9229，9119，9009
    //1位数所有1*9=9，2位数99*91=9009，三位数999999 998899 997799
    //似乎没有办法，只能一个个尝试
    //对于n位数，我们依次构建所有回文n=1直接返回9，
    //其他比如2位，最大值99*99=9801，最小值10*10=1000我们依次构造1001 1111 1221......9779 9669,顺序从大到小
    int largestPalindrome(int n) {
        if(n==1) return 9;
        int max=pow(10,n)-1;
        int min=pow(10,n-1);
        for(int i=max;i>=min;i--)
        {
            string s=to_string(i);
            string copy=s;
            reverse(copy.begin(),copy.end());
            s+=copy;//构造出的回文
            

            long long num=stoll(s);
            //当n>1时，两个n位数乘积的最大回文数一定是2n位的
            //int new_min=(pow(10,2n)-1)
            for(long long i=max;i*i>num;--i)
            {
                if(num%i==0)
                {   
                    //int j=num/i;
                    //if(j>min&&j<max)
                    //{
                        cout<<num<<endl;
                        return num%1337;
                   // }
                     
                }
                    
            }           
        }
        return 0;       
    }
};
