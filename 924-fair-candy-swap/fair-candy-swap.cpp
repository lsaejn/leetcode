// Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.
//
// Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
//
// Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
//
// If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.
//
//  
//
//
// Example 1:
//
//
// Input: A = [1,1], B = [2,2]
// Output: [1,2]
//
//
//
// Example 2:
//
//
// Input: A = [1,2], B = [2,3]
// Output: [1,2]
//
//
//
// Example 3:
//
//
// Input: A = [2], B = [1,3]
// Output: [2,3]
//
//
//
// Example 4:
//
//
// Input: A = [1,2,5], B = [2,4]
// Output: [5,4]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	1 <= B.length <= 10000
// 	1 <= A[i] <= 100000
// 	1 <= B[i] <= 100000
// 	It is guaranteed that Alice and Bob have different total amounts of candy.
// 	It is guaranteed there exists an answer.
//
//
//
//
//


class Solution {
public:
    //得到差值i，然后找到两个数差值为i即可
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1=accumulate(A.begin(),A.end(),0);
        int sum2=accumulate(B.begin(),B.end(),0);
        int target=0.5*(sum2-sum1);
        //数量比较大，用二分查找
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        for(int i=0;i!=A.size();++i)
        {
            int target_in_B=A[i]+target;
            int begin=0;
            int end=B.size()-1;
            while(begin<=end)
            {
                int mid=(end+begin)/2;
                if(B[mid]>target_in_B) end=mid-1;
                else if(B[mid]<target_in_B) begin=mid+1;
                else if(B[mid]==target_in_B) return {A[i],B[mid]};
            }
        }
        return {};
    }
};
