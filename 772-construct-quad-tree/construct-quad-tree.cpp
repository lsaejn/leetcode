// We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.
//
// Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.
//
// Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:
//
// Given the 8 x 8 grid below, we want to construct the corresponding quad tree:
//
//
//
// It can be divided according to the definition above:
//
//
//
//  
//
// The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.
//
// For the non-leaf nodes, val can be arbitrary, so it is represented as *.
//
//
//
// Note:
//
//
// 	N is less than 1000 and guaranteened to be a power of 2.
// 	If you want to know more about the quad tree, you can refer to its wiki.
//
//


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
//这道题还是很酷的。显然要使用递归
class Solution {
private:
    Node* dfs(vector<vector<int>>& grid, int x, int y, int length) {
        if (length == 1)    //遍历到了最后的1*1的网格，创建节点
            return new Node(grid[x][y] == 1? true : false, true, nullptr, nullptr, nullptr, nullptr);
        length /= 2;
        //递归
        auto topLeft = dfs(grid, x, y, length);
        auto topRight = dfs(grid, x, y + length, length);
        auto bottomLeft = dfs(grid, x + length, y, length);
        auto bottomRight = dfs(grid, x + length, y + length, length);

        //满足四个叶子节点的合并条件
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val&& bottomLeft->val == bottomRight->val)
        {
            bool v = topLeft->val;  //设置这个合并的新节点的值
            delete topLeft;  //删除原先的这四个节点
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(v, true, nullptr, nullptr, nullptr, nullptr);
        } 
        else 
            return new Node(true, false, topLeft, topRight, bottomLeft,  bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) 
            return nullptr;
        return dfs(grid, 0, 0, grid.size());
    }
};
