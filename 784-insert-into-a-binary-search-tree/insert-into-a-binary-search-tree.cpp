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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * NodeToInsert=new TreeNode(val);
        if(root==NULL)return NodeToInsert;
        TreeNode * prev=NULL, * cur=root;
        bool flag=1;
        while(cur){
            if(val<cur->val){
                prev=cur;
                cur=cur->left;
                flag=0;
            }
            else{
                prev=cur;
                cur=cur->right;
                flag=1;
            }

        } 
        if(flag==0)prev->left=NodeToInsert;
        else prev->right=NodeToInsert;
        return root;
    }
};