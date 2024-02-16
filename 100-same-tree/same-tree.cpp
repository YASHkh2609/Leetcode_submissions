/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkSame(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)return true;
        if((p && !q) || (!p && q))return false; 

        bool left=checkSame(p->left, q->left);
        if(!left)return false;
        bool right=checkSame(p->right, q->right);
        if(!right)return false;

        if(p->val==q->val)return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p,q);
    }
};