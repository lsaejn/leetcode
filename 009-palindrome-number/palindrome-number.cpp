// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
//
// Input: 121
// Output: true
//
//
// Example 2:
//
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//
// Example 3:
//
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
// Follow up:
//
// Coud you solve it without converting the integer to a string?
//


class Solution {
public:
    bool isPalindrome(int x) {//1221
        if (x < 0) return false;
        int num_of_ten=1;
        while(x/num_of_ten>=10)
            num_of_ten*=10;
        while(x)
        {
            if(x/num_of_ten==x%10)
            {
                x=x%num_of_ten;//去掉最高位
                x/=10;//最低位
                num_of_ten/=100;
            }
            else
                return false;
            
        }
        return true;
        
    }
};
