//
// A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
//
// The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus.  A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
//
// Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall.
// Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.
//
// Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.
//
//
// Example 1:
//
// Input: grid = 
// [[0,1,0,0,0,0,0,1],
//  [0,1,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,0]]
// Output: 10
// Explanation:
// There are 2 contaminated regions.
// On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
//
// [[0,1,0,0,0,0,1,1],
//  [0,1,0,0,0,0,1,1],
//  [0,0,0,0,0,0,1,1],
//  [0,0,0,0,0,0,0,1]]
//
// On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
//
//
//
// Example 2:
//
// Input: grid = 
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output: 4
// Explanation: Even though there is only one cell saved, there are 4 walls built.
// Notice that walls are only built on the shared boundary of two different cells.
//
//
//
// Example 3:
//
// Input: grid = 
// [[1,1,1,0,0,0,0,0,0],
//  [1,0,1,0,1,1,1,1,1],
//  [1,1,1,0,0,0,0,0,0]]
// Output: 13
// Explanation: The region on the left only builds two new walls.
//
//
//
// Note:
//
// The number of rows and columns of grid will each be in the range [1, 50].
// Each grid[i][j] will be either 0 or 1.
// Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.
//
//


class Solution {
public:
    //这应该是我刷leetcode最恶的题了吧。。。
	vector<pair<int, int>> dir = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
	map<int, bool>closed;

	int containVirus(vector<vector<int>>& grid) 
    {
		int result = 0;
		int count = 0;
		//我们先计算连通域个数
		for (int i = 0; i<grid.size(); ++i)
			for (int j = 0; j != grid[0].size(); ++j)
				helper(grid, i, j, count, 0);
        

		int left = -count;//活动病毒的区域
		
		for (int i = count; i < 0; ++i)//用一个表记录病毒区域是否被锁住
			closed.insert({ i,false });
        
		while (left>0)//我们运行到区域全被锁住
		{
			multiset<pair<int, int>> max_fection;//即将被感染的格子数和wall的数量不同，所以允许重复，它就是wall的数量。
			int maxid = count;//即将被感染的最多区域的id
			int i = count;
			for (; i != 0; ++i)//循环得到各个区域感染的区域
			{
				if (closed[i]) continue;
				auto num_fection = getInfectionInNextRound(i, grid);
				{
					set<pair<int, int>> ma(max_fection.begin(), max_fection.end());//去掉重复就是即将被感染的格子数
					set<pair<int, int>> nu(num_fection.begin(), num_fection.end());
					if (nu.size() > ma.size())
					{
						max_fection = num_fection;
						maxid = i;
					}
				}

			}
			closed[maxid] = true;//我们将这个区域关闭		
			result += max_fection.size();//记录数量
			left--;//活动的区域-1
			if (left == 0) break;//我们提前结束循环
			spread(grid,count,left);//剩下的区域可以传播病毒了，如果有连通的区域，我们也合并
			unionGrid(grid, left);//传播后如果有连通的区域，我们合并
		}
		return result;
	}

	void helper(vector<vector<int>>& grid, int x, int y, int& count, int num_pass)
	{
		if (!validPosition(x, y, grid))
			return;
		if (grid[x][y] == 1)
		{
			grid[x][y] = (num_pass == 0 ? --count : num_pass);
			for (auto &direct : dir)
				helper(grid, x + direct.first, y + direct.second, count, grid[x][y]);
		}
	}

	bool validPosition(int x, int y, vector<vector<int>>& grid)
	{
		if (x<0 || x >= grid.size() || y<0 || y >= grid[0].size())
			return false;
		return true;
	}

	multiset<pair<int, int>> getInfectionInNextRound(int serialNumber, vector<vector<int>>& grid)
	{
		multiset<pair<int, int>> infection;
		for (int i = 0; i<grid.size(); ++i)
			for (int j = 0; j != grid[0].size(); ++j)
			{
				if (grid[i][j] == serialNumber)
					for (int x = 0; x != dir.size(); ++x)
					{
						if (!validPosition(i + dir[x].first, j + dir[x].second, grid) || grid[i + dir[x].first][j + dir[x].second] != 0) 
							continue;
						infection.insert({ i + dir[x].first,j + dir[x].second });
					}
			}
		return infection;
	}

	void spread(vector<vector<int>>& grid,int count,int& left)
	{
		map<int, multiset<pair<int, int>>> areas;
		for (int i = count; i != 0; ++i)
		{
			if (closed[i]) continue;
			auto area = getInfectionInNextRound(i, grid);
			areas[i] = area;
		}
		for (int i = count; i != 0; ++i)
		{
			vector<int> toClose;
			if (closed[i]) continue;
			auto area =areas[i];
			for (auto &elem : area)
			{
				if (grid[elem.first][elem.second] != 0||closed[grid[elem.first][elem.second]])//只是为了让逻辑更清楚
                    continue;
				else
					grid[elem.first][elem.second] = i;
			}
			left -= toClose.size();
		}
		
	}
	//如果每次扩散后不union,下一次的感染区域没办法计算了。原因是两个区域可能连在一起，而它们下次的感染区域没有交集
	void unionGrid(vector<vector<int >> &grid,int &left)
	{
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j != grid[0].size(); ++j)
			{
				if (grid[i][j] == 0|| closed[grid[i][j]]==true) 
                    continue;
				else//grid[i][j] is virus
				{
					for (int x = 0; x != dir.size(); ++x)
					{
						int target_x = i + dir[x].first;
						int target_y = j + dir[x].second;
						if (!validPosition(target_x, target_y, grid)||grid[target_x][target_y]==0||closed[grid[target_x][target_y]]) 
							continue;
						else 
						{
							int oldID = grid[target_x][target_y];
							if (oldID == grid[i][j]) continue;
							for (int k = 0; k < grid.size(); ++k)
								for (int m = 0; m != grid[0].size(); ++m)
									if (grid[k][m] == oldID)
											grid[k][m] = grid[i][j];
							closed[oldID] = true;
							left--;
						}
					}
				}
			}
	}   
};
