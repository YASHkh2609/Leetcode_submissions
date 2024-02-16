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
    int height(TreeNode* root){
        if(root==NULL)return 0;
    // we are returning height of tree only if it is balanced else we return -1
        int lh=height(root->left);
        if(lh==-1)return -1;
        int rh=height(root->right);
        if(rh==-1)return -1;
        if(abs(lh-rh)>1)return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return (height(root)!=-1);
        // TC: O(N^2) because we traverse all nodes to check balanced and need to calculate height at each node
        // if(root==NULL)return true;
    
        // int lh=height(root->left);
        // int rh=height(root->right);

        // if(abs(lh-rh)>1)return false;

        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);

        // if( !left || !right )return false;

        // return true;
    }

};