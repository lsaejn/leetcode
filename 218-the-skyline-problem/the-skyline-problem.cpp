// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//
//
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
//
// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
//
// Notes:
//
//
// 	The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// 	The input list is already sorted in ascending order by the left x position Li.
// 	The output list must be sorted by the x position.
// 	There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


    /*    
Step 1:

Use a multimap to sort all boundary points. For a start point of an interval, let the height be positive; otherwise, let the height be negative. Time complexity: O(n log n)

Step 2:

Use a multiset (rather than a heap/priority_queue) to maintain the current set of heights to be considered. If a new start point is met, insert the height into the set, otherwise, delete the height. The current max height is the back() element of the multiset. For each point, the time complexity is O(log n). The overall time complexity is O(n log n).

Step 3:

Delete the points with equal heights. Time: O(n)
    */
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

        // Step 1:
		multimap<int, int> coords;
		for (const vector<int> & building : buildings) {
			coords.emplace(building[0], building[2]);
			coords.emplace(building[1], -building[2]);
		}

        // Step 2:
		multiset<int> heights = { 0 };
		map<int, int> corners;
		for (const pair<int, int> & p : coords) {
			if (p.second > 0) {
				heights.insert(p.second);
			}
			else {
				heights.erase(heights.find(-p.second));
			}
			int cur_y = *heights.rbegin();
			corners[p.first] = cur_y;
		}

        // Step 3:
		function<bool(pair<int, int> l, pair<int, int> r)> eq2nd = [](pair<int, int> l, pair<int, int> r){ return l.second == r.second;  };
		vector<pair<int, int>> results;
		unique_copy(corners.begin(), corners.end(), back_insert_iterator<vector<pair<int, int>>>(results), eq2nd);
		return results;
	}
};
