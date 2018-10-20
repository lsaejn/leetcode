// A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, bottomLeft and bottomRight. Quad trees are often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.
//
// We want to store True/False information in our quad tree. The quad tree is used to represent a N * N boolean grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same. Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.
//
// For example, below are two quad trees A and B:
//
//
// A:
// +-------+-------+   T: true
// |       |       |   F: false
// |   T   |   T   |
// |       |       |
// +-------+-------+
// |       |       |
// |   F   |   F   |
// |       |       |
// +-------+-------+
// topLeft: T
// topRight: T
// bottomLeft: F
// bottomRight: F
//
// B:               
// +-------+---+---+
// |       | F | F |
// |   T   +---+---+
// |       | T | T |
// +-------+---+---+
// |       |       |
// |   T   |   F   |
// |       |       |
// +-------+-------+
// topLeft: T
// topRight:
//      topLeft: F
//      topRight: F
//      bottomLeft: T
//      bottomRight: T
// bottomLeft: T
// bottomRight: F
//
//
//  
//
// Your task is to implement a function that will take two quadtrees and return a quadtree that represents the logical OR (or union) of the two trees.
//
//
// A:                 B:                 C (A or B):
// +-------+-------+  +-------+---+---+  +-------+-------+
// |       |       |  |       | F | F |  |       |       |
// |   T   |   T   |  |   T   +---+---+  |   T   |   T   |
// |       |       |  |       | T | T |  |       |       |
// +-------+-------+  +-------+---+---+  +-------+-------+
// |       |       |  |       |       |  |       |       |
// |   F   |   F   |  |   T   |   F   |  |   T   |   F   |
// |       |       |  |       |       |  |       |       |
// +-------+-------+  +-------+-------+  +-------+-------+
//
//
// Note:
//
//
// 	Both A and B represent grids of size N * N.
// 	N is guaranteed to be a power of 2.
// 	If you want to know more about the quad tree, you can refer to its wiki.
// 	The logic OR operation is defined as this: "A or B" is true if A is true, or if B is true, or if both A and B are true.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
class Solution {//多叉索引树有很多应用，比如地图，字符串解析。这个例子比较简单，递归比较即可
public://这道题的难度在于。。。英文描述
    Node* intersect(Node* quadTree1, Node* quadTree2) 
    {
        if(!quadTree1||!quadTree2) return nullptr;
        if(quadTree1->isLeaf&&quadTree2->isLeaf) return new Node(quadTree1->val||quadTree2->val,true,nullptr,nullptr,nullptr,nullptr);
        if((quadTree1->isLeaf&&quadTree1->val)||(quadTree2->isLeaf&&quadTree2->val))
            return new Node(true,true,nullptr,nullptr,nullptr,nullptr);
        if(quadTree1->isLeaf&&!quadTree1->val) return quadTree2;//need a copy,but we cheat it
        if(quadTree2->isLeaf&&!quadTree2->val) return quadTree1;
        else
        {
            auto topLeft=intersect(quadTree1->topLeft,quadTree2->topLeft);
            auto topRight=intersect(quadTree1->topRight,quadTree2->topRight);
            auto bottomLeft=intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
            auto bottomRight=intersect(quadTree1->bottomRight,quadTree2->bottomRight);
            if(topLeft->val&&topRight->val&&bottomLeft->val&&bottomRight->val)
            {
                delete topLeft;
                delete topRight;
                delete bottomLeft;
                delete bottomRight;
              return new Node(true,true,nullptr,nullptr,nullptr,nullptr);  
            }                
            else
                return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
        }
    }
    
    Node* DoCopy(Node* src)
    {
        if(!src) return src;
        auto copy=new Node(src);
        copy->topLeft = DoCopy(src->topLeft);
        copy->topRight = DoCopy(src->topRight);
        copy->bottomLeft = DoCopy(src->bottomLeft);
        copy->bottomRight = DoCopy(src->bottomRight);
    }
};
