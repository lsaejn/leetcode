// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//
//
// Example:
//
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1;
        string num2;
        auto head=l1;
        while(l1||l2)
        {
            if(l1)
            {
                num1.push_back(l1->val+'0');
                l1=l1->next;
            }
            if(l2)
            {
               num2.push_back(l2->val+'0');
               l2=l2->next;
            }           
        }
        auto re=add(num1,num2);
        cout<<num1<<"+"<<num2<<"="<<re<<endl;
        l1=head;
        for(int i=0;i!=re.size();++i)
        {
            l1->val=re[i]-'0';
            if(i+1<re.size()&&!l1->next)
            {
                l1->next=new ListNode(0);
            }
            l1=l1->next;           
        }
        return head;
    }
    
    string add(string& num1,string& num2)//1230+12300
    {
        reverse(num1.begin(),num1.end());//0321
        reverse(num2.begin(),num2.end());//00321
        int max_size=max(num1.size(),num2.size());
        if(num1.size()<num2.size()) swap(num1,num2);
        int pro=0;
        string re;
        for(int i=0;i!=max_size;++i)
        {
            if(i<num2.size())
            {
                int temp=(num1[i]-'0')+(num2[i]-'0')+pro;
                re+=temp%10+'0';
                pro=temp>=10?1:0;
            }
            else
            {
                int temp=(num1[i]-'0')+pro;
                re+=temp%10+'0';
                pro=temp>=10?1:0;
            }
        }
        if(pro!=0)
            re+=pro+'0';
        reverse(re.begin(),re.end());
        return re;       
    }
};
