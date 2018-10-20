// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.
//
// Example:
//
//
// int k = 3;
// int[] arr = [4,5,8,2];
// KthLargest kthLargest = new KthLargest(3, arr);
// kthLargest.add(3);   // returns 4
// kthLargest.add(5);   // returns 5
// kthLargest.add(10);  // returns 5
// kthLargest.add(9);   // returns 8
// kthLargest.add(4);   // returns 8
//
//
// Note: 
// You may assume that nums' length ≥ k-1 and k ≥ 1.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class KthLargest {
public:
    //用最大堆的原因在于，我们可以始终保持k个元素，因为用户无法删除元素。
    //但取值时又不方便，所以使用multiset是最轻松的
    KthLargest(int k, vector<int> nums){
        max=k;
        if(nums.size()>max)
            std::sort(nums.begin(),nums.end(),std::greater<int>());
        for(auto elem:nums)
        {
            col.push(elem);
            if(--k==0) break;
        }
    }
    
    int add(int val) {//85432
        if(col.size()<max)
            col.push(val);
        else{
            if(val<col.top()) return col.top();
            else{
                col.push(val);
                col.pop();
                return col.top();
            }
        }
        return col.top();
            
    }
    std::priority_queue<int, std::vector<int>, std::greater<int> > col;
    int max;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
