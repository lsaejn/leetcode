// There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].
//
// Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:
//
//
// 	Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
// 	Every worker in the paid group must be paid at least their minimum wage expectation.
//
//
// Return the least amount of money needed to form a paid group satisfying the above conditions.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: quality = [10,20,5], wage = [70,50,30], K = 2
// Output: 105.00000
// Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
//
//
//
// Example 2:
//
//
// Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
// Output: 30.66667
// Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
//
//
//  
//
// Note:
//
//
// 	1 <= K <= N <= 10000, where N = quality.length = wage.length
// 	1 <= quality[i] <= 10000
// 	1 <= wage[i] <= 10000
// 	Answers within 10^-5 of the correct answer will be considered correct.
//
//
//


class Solution {
public:
    //我把wage/quality称为性价比，显然，对于例2，如果以quality=10,wage=2,ratio=2/10=0.2的那个员工为基准，花费将是最小的。
    //只需要花费3*0.2+1*0.2+10*0.2+10*0.2+1*0.2即可
    //但是这是不可能的，因为有个最低工资.3至少要支付4(你想支付0.6是做梦)，这告诉我们，如果我们选出ratio最小的3个数a,b,c,那么基准(ratio)必须是最后一个，也就是最大的那个，这样才能让3个数都达到最低工资
    //达到最低工资了并不能保证总花费最低，因为有的员工数量很多，提高了基准意味着这些员工的花费水涨船高。
    //我们要做的就是把数量最多的这个元素踢出来。重新计算总花费。
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int N = quality.size();
        vector<pair<double, int>>vec; // ratio, quality
        for(int i = 0; i < N; i++) 
            vec.push_back(make_pair(wage[i] * 1.0 / quality[i], quality[i])); 

        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.first < b.first;
        });
        int quality_cnt = 0;
        priority_queue<int> q; // max-min heap
        for(int i = 0; i < K; i++)//放前K个员工数据即可
        {
            quality_cnt += vec[i].second;
            q.push(vec[i].second);
        }
        double ans = quality_cnt * vec[K - 1].first;
        //其实我不太明白为什么要这么比较，主要是不知道他们是怎么想出来了。。。        
        for(int i = K; i < N; i++) {
            q.push(vec[i].second);
            quality_cnt += vec[i].second;
            quality_cnt -= q.top();
            q.pop();
            ans = min(ans, quality_cnt * vec[i].first);
        }
        
        return ans;
    }
};
