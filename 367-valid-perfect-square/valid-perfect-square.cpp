// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
//
//
// Input: 16
// Output: true
//
//
//
// Example 2:
//
//
// Input: 14
// Output: false
//
//
//
//


class Solution {
public:
    //如果是暴力，那么要求出INT32_MAX里最大的完全平方数，这有点赖皮
    //21，0000，0000 这么一分，最大完全平方数在4万到5万之间，我们取5万，用一个long表示平方的结果
    bool isPerfectSquare(int num) {
        int begin=0;
        int end=50000;
        long long result=0;
        while(begin<=end)
        {
            long long mid=(end-begin)/2+begin;//ok
            cout<<begin<<" "<<end<<" "<<mid<<endl;
            result=mid*mid;
            if(mid==46875) cout<<result;//两个int 相乘，结果还是int
            if(result==num)
                return true;
            if(result<num)
            {
                
                begin=mid+1;
            }
            else
            {
                end=mid-1;
            }
            
        }
        return false;
        
    }
};
