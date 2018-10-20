// You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id. 
//
// For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
//
// Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
//
// Example 1:
//
// Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
// Output: 11
// Explanation:
// Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
//
//
//
// Note:
//
// One employee has at most one direct leader and may have several subordinates.
// The maximum number of employees won't exceed 2000.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> s;
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        return helper(id, m, s);
    }
    //这个题不是我们想写成递归，而是。。。它本来就是个传递的过程
    int helper(int id, unordered_map<int, Employee*>& m, unordered_set<int>& s) {
        if (s.count(id)) return 0;
        s.insert(id);
        int res = m[id]->importance;
        for (int num : m[id]->subordinates) {
            res += helper(num, m, s);
        }
        return res;
    }
};