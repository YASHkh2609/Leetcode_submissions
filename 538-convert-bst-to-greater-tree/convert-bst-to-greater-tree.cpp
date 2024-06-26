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
    void helper(TreeNode * root, int& nodeSum){
            if(root==NULL)return;

            helper(root->right, nodeSum);
            nodeSum+=root->val;
            root->val=nodeSum;
            helper(root->left, nodeSum);
        }
    TreeNode* convertBST(TreeNode* root) {
        int nodeSum=0;
        helper(root, nodeSum);
        return root;
    }
};