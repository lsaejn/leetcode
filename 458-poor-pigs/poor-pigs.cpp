// There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.
//
// Answer this question, and write an algorithm for the follow-up general case.
//
// Follow-up: 
//
// If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
//


class Solution {
public:
    /*
        先考虑只喝一次，也就是只给15分钟
    1.让猪去随便喝一桶，如果毒死了，就是喝的那桶，反之则是另一桶。0/1
    2.好，那么如果有两只猪呢，能测几桶？怎么喝呢，两只猪一猪喝一桶，再同时喝一桶，剩下一桶谁也不喝，那么如果两只猪都毒死了，说明是共同喝的那桶有毒，如果某    个猪毒死了，说明该猪喝的那桶有毒，如果都没事，说明是谁也没喝的那桶。00/01/10/11
    3.三只猪分别喝1，2，3，两只猪喝4，两只喝5，两只喝6，三只都喝7，三只都不喝8.000/001/010/011/100/101/110/111(把每位想成一直猪,每个数字对应一个桶)
    //那么给30分钟呢？
    如果能测两次的话，情况就不一样了，我们就可以重复利用猪了。比如还是两只猪，能测两次，功能测几个桶，答案可以测9桶，为啥，我们组个二维数组：
    1  2  3
    4  5  6
    7  8  9
    如果我们让第一头猪第一次喝1，2，3桶，第二次喝4，5，6桶，而让第二头猪第一次喝1，4，7桶，第二次喝2，5，8桶，我们可以根据猪的死亡情况来确定是哪一桶的问        题，实际上就把猪被毒死的那个节点当作了二维数组的横纵坐标来定位毒桶的位置

    //难度在于这个喝水次数如何转化成数学，现在每个位可以表示0/1，但是第30分钟死和第15分钟死是两个概念，也就是说
    //每只猪能喝两桶水了0000 0001 0010 0100 0101 0110 1000 1001 1010，就这9种，比如0010，表示第一只猪第一次第二次都不喝，第二只猪第一次喝。
    //在这里，1100，0011显然没有意义，因为1100和1000/0100结果重复。也就是每只猪都不要11出现*/
    //那么3只猪呢？每只猪给桶的状态只有3个00,01,10,不存在第一次喝第二次也喝，也是说，猪是000 001 010 100 101 110,so 3*3*3
    //显然，4只猪是3**4
    //好，推广一下，45分钟呢，每只猪现在有了000 001 010 100,是的，是4个状态，不应该将同一个桶喝两次
    //结果差不多出来了n只猪，每只有m=minutesToTest / minutesToDie+1个状态 n**m就是它能计算的桶的数量
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
       return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1)); 
    }
};
