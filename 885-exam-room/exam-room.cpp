// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
//
// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)
//
// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
//
//  
//
// Example 1:
//
//
// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
// Output: [null,0,9,4,2,null,5]
// Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
//
//
// ​​​​​​​
//
// Note:
//
//
// 	1 <= N <= 10^9
// 	ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
// 	Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class ExamRoom {
public:
    // When a student enters the room
    // they must sit in the seat that maximizes the distance to the closest person. 
    set<int>seats; // 已经被坐上的位置
    int n;
    ExamRoom(int N)
    {
        n = N;
    }
    /*
    每次先检查0和最后一个位置是否坐了人，因为这两个位置只需要考虑一边。
    但中间的部分要考虑两边
    */
    int seat() {
        int ins_idx = 0; // 这次要插入的位置
        if(seats.size() == 0) 
        {// no one  in the room
            seats.insert(0);
            return 0; 
        }
        if(seats.size())
        {
            int maxLen = 0;
            // 0没有被占
            if(!seats.count(0)) 
            { // no one sit on the 0
                maxLen = *seats.begin();
                //ins_idx = 0;
            }
            int idx = 0; // 记录上一个人的位置
            // 检查中间
            auto begin = seats.begin();
            auto end=  seats.end();
            while(begin != end) 
            {
                int len = (*begin - idx) / 2;
                if(len > maxLen) {
                    maxLen = len;
                    ins_idx = (*begin + idx) / 2;
                }
                idx = *begin;
                begin++;
            }
            // 最后的位置没有被占
            if(!seats.count(n - 1))
            {
                int len = n - 1 - *seats.rbegin();
                if(len > maxLen) {
                    maxLen = len;
                    ins_idx = n - 1;
                }
            }
        }
        seats.insert(ins_idx);
        return ins_idx;
    }
    
    void leave(int p) {
        seats.erase(seats.find(p));
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
