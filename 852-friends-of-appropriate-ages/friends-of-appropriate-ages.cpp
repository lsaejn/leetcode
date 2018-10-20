// Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 
//
// Person A will NOT friend request person B (B != A) if any of the following conditions are true:
//
//
// 	age[B] <= 0.5 * age[A] + 7
// 	age[B] > age[A]
// 	age[B] > 100 && age[A] < 100
//
//
// Otherwise, A will friend request B.
//
// Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
//
// How many total friend requests are made?
//
// Example 1:
//
//
// Input: [16,16]
// Output: 2
// Explanation: 2 people friend request each other.
//
//
// Example 2:
//
//
// Input: [16,17,18]
// Output: 2
// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
//
// Example 3:
//
//
// Input: [20,30,100,110,120]
// Output: 
// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
//
//
//  
//
// Notes:
//
//
// 	1 <= ages.length <= 20000.
// 	1 <= ages[i] <= 120.
//


class Solution {
public:
    //A能发的对象B，要求 1，B不能年龄大于自己，2 B不能小于等于自己一半年龄+7(14的对象必须大于14，不符合条件1.所以参与者最小15岁的对象)
    //显然要排序，每个人要从自己左边找
    //注意，可以同龄，我们要计算当前同龄个数求出C(n,2)*2,这很容易做到
    //OK，我们要写的函数包括:是否能发送请求canSendMessage，C(n,2)
    //遍历时一个记录元素值current和个数的count
int numFriendRequests(vector<int>& ages)
{
  int a[121] = {}, res = 0;
  for (auto age : ages) 
      ++a[age];
  for (auto i = 15; i <= 120; ++i)//15-120岁
    for (int j = 0.5 * i + 8; j <= i; ++j) //条件2到条件1的所有人
        //a[i]是发送者，a[j]接受者。你懂的，如果发送者接受者都是16岁，要减去自己。比如20人，只能是C(n,2)*2=n*(n-1)*0.5*2=n*n-1,否则是n*n
        res += a[j] * (a[i] - (i == j));
  return res;
}
    
};
