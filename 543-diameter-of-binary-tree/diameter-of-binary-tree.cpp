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
    int height(TreeNode* root, int &maxi){
        if(root==NULL)return 0;

        int lh=height(root->left, maxi);
        int rh=height(root->right, maxi);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    // int height1(TreeNode* root){
    //     if(root==NULL)return 0;

    //     int lh=height1(root->left);
    //     int rh=height1(root->right);

    //     return 1+max(lh,rh);
    // }
    // int maxi=0;
    // void give_diameter(TreeNode* root, int &maxi){
    //     if(root==NULL) return;

    //     int lh=height1(root->left);
    //     int rh=height1(root->right);

    //     maxi=max(maxi, lh+rh);
    //     give_diameter(root->left, maxi);
    //     give_diameter(root->right, maxi);

    //}
    int diameterOfBinaryTree(TreeNode* root){
        //TC: O(N^2), no extra space just stack space for resursion
        //give_diameter(root, maxi);
        //return maxi;

        //O(N) soln
        int maxi=0;
        int h= height(root, maxi);
        return maxi;
    }
};