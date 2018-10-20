//
// Given a sorted array, two integers k and x, find the k closest elements to x in the array.  The result should also be sorted in ascending order.
// If there is a tie,  the smaller elements are always preferred.
//
//
// Example 1:
//
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
//
//
//
//
// Example 2:
//
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
//
//
//
// Note:
//
// The value k is positive and will always be smaller than the length of the sorted array.
//  Length of the given array is positive and will not exceed 104
//  Absolute value of elements in the array and x will not exceed 104
//
//
//
//
//
//
// UPDATE (2017/9/19):
// The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
    /*
        思路相当简单：
        1.找到和target最接近的数
        2.向左右扩散，左边到头，从右选取，反之亦然
    */
int getClosetIdx(vector<int>& arr,int x)
{
    //测试用例:1,3,5,7---6
    //1,3,5,7---2
    int lo=0,hi=arr.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]<x)
                lo=mid+1;
            else
                hi=mid-1;
        }
    return abs(arr[lo]-x)<abs(arr[hi]-x)?lo:hi;
}
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(x<=arr[0])
            return vector<int>(arr.begin(),arr.begin()+k);
        else if(x>=arr.back())
            return vector<int>(arr.end()-k,arr.end());
        int idx=getClosetIdx(arr,x);
        list<int> t;
        t.push_back(arr[idx]);
        int n=1;
        int i=idx-1,j=idx+1;
        //这几个循环写得不好
        while(n<k)
        {
            if(i<0||j>=arr.size())
                break;
            if(abs(arr[j]-x)<abs(x-arr[i])){
                t.push_back(arr[j]);
                j++;
            }
            else if(abs(arr[j]-x)>=abs(x-arr[i])){
                t.insert(t.begin(),arr[i]);
                i--;
            }
            n++;
        }
        while(n<k && i>=0){
            t.insert(t.begin(),arr[i]);
            n++;i--;
        }
        while(n<k && j<arr.size()){
            t.push_back(arr[j]);
            n++; j++;
        }
        return vector<int>(t.begin(),t.end());
    }
};
