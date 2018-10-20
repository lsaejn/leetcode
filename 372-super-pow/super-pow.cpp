//
// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//
// Example1:
//
// a = 2
// b = [3]
//
// Result: 8
//
//
//
// Example2:
//
// a = 2
// b = [1,0]
//
// Result: 1024
//
//
//
// Credits:Special thanks to @Stomach_ache for adding this problem and creating all test cases.


class Solution {
public:
    //首先要思考的是为什么b要以数组形式给出。
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }
    int pow(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % 1337;
        return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
    }
};
