// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


class Solution {
public:
    //如果单向查找，我们最终会停在最高点上。最高点的右边无法计算
    //所以我们要双向计算，同时朝最高点行走。
    //下面这个解法同时进行。。。
    int trap(vector<int> A) {
        int left=0; int right=A.size()-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right)
        {
            if(A[left]<=A[right])//left<=right,水最终会从左边流走，所以保存left，再看能不能在右边找到高墙
            {
                if(A[left]>=maxleft) 
                    maxleft=A[left];
                else 
                    res+=maxleft-A[left];
                left++;
            }
            else
            {
                if(A[right]>=maxright) 
                    maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
