// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// Example:
//
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
//
//
//
// Note:
//
// You may assume that the array does not change.
// There are many calls to sumRange function.
//
//


class NumArray {
public:
    NumArray(vector<int> nums):numsCol(std::move(nums)) {
        
        
    }
    
    int sumRange(int i, int j) {
        auto sum=0L;
        while(i<=j)
        {
            sum+=numsCol[i];
            ++i;
        }
        if(sum>INT32_MAX) return INT32_MAX;
        return sum;
        
    }
    private:
    vector<int> numsCol;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
