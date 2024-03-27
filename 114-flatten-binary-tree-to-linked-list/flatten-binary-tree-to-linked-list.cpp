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
    // void pre_order(TreeNode* root,vector<int>&preorder){
    //     if(root==NULL)return;

    //     preorder.push_back(root->val);
    //     pre_order(root->left, preorder);
    //     pre_order(root->right, preorder);
    // }
    //TreeNode * prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        // vector<int>preorder;
        // pre_order(root, preorder);

        // root->left=NULL;
        // root->right=NULL;
        // TreeNode * temp=root;
        // for(int i=1;i<preorder.size();i++){
        //     temp->right= new TreeNode(preorder[i]);
        //     temp=temp->right; 
        // }
        // temp->right=NULL;
        //Approach1
        // flatten(root->right);
        // flatten(root->left);

        // root->right=prev;
        // root->left=NULL;
        // prev=root;
        //Approach 2
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left){
                TreeNode* prev=cur->left;
                while(prev->right)prev=prev->right;

                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};