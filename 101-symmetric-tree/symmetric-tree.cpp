// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//
// But the following [1,2,2,null,3,null,3]  is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //把层次遍历写出来即可
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) 
           return true;  
        deque<TreeNode*> currentLevel, nextLevel;  
        currentLevel.push_back(root); 
        
        while (!currentLevel.empty()) 
        {            
            TreeNode*currNode = currentLevel.front(); 
            currentLevel.pop_front();  
            if (currNode) {  
                nextLevel.push_back(currNode->left);  
                nextLevel.push_back(currNode->right);  
            }  
            if (currentLevel.empty()) {  
                //swap(currentLevel, nextLevel);  
                currentLevel=nextLevel;
                cout<<currentLevel.size()<<endl;
                nextLevel.clear();
                
                            //检查当前层
                for(int i=0,j=currentLevel.size()-1;j-i>=1;++i,--j)
                {
                    TreeNode* Node1 = currentLevel[i];
                    TreeNode* Node2 = currentLevel[j]; 
                    if(!Node1&&!Node2)
                    {
                        cout<<"指针不对1"<<endl;
                    }  
                    else if(Node1&&Node2)
                    {
                        cout<<"指针不对2"<<endl;
                        if(Node1->val==Node2->val)
                        {
                            cout << Node1->val<<"=="<<Node2->val << endl; 
                            continue;                        
                        }  
                        else
                            return false;
                    }

                    else
                    {
                        cout<<"指针不对3"<<endl;
                        return false;
                    }
                }
                
            }  
        }  
        return true;
    }

};

