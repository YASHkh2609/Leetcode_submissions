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
    int left_height(TreeNode* root){
        int height=0;
        TreeNode* temp=root;
        while(temp!=NULL){
            height++;
            temp=temp->left;
        }
        return height;
    }
    int right_height(TreeNode* root){
        int height=0;
        TreeNode* temp=root;
        while(temp!=NULL){
            height++;
            temp=temp->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        
        int lh=left_height(root);
        int rh=right_height(root);

        if(lh==rh)return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};