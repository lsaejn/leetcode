// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.
//
//


#define MAX 30
struct trie{
    int num;
    trie *child[2];
};
trie* newnode(){
    trie *temp = new trie;
    temp->child[0]=temp->child[1]=NULL;
    temp->num = 0;
    return temp;
}
void insert(trie* root,int n){//单词树里插入n
   // trie *temp = root;
    for(int i=MAX;i>=0;i--){//注意，32层，0 ≤ ai < 2**31 。所以
        bool res = ((n)&(1<<i));//从高位开始放
        if(root->child[res]==NULL)
            root->child[res]=newnode();
        root=root->child[res];
    }
    root->num = n;
    return;
}
int fxor(trie *root,int n){//nums[i]对整个树做异或，
    //trie *temp = root;
    for(int i=MAX;i>=0;i--){
        bool res = ((n)&(1<<i));
        if(root->child[1-res]!=NULL)root=root->child[1-res];
        else if(root->child[res]!=NULL)root=root->child[res];
    }
    return (root->num)^(n);
}
class Solution {
public:
    //int正数的最大值是2**32-1,01111111 11111111 11111111 11111111
    //我们令root为0，然后构造这棵树
    int findMaximumXOR(vector<int>& nums) {
        trie *root = newnode();
        insert(root,nums[0]);
        int res = 0;
        for(int i=1;i<nums.size();i++){
            int val = fxor(root,nums[i]);
            res = max(res,val);
            insert(root,nums[i]);
        }
        return res;
       
    }
};
