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
    TreeNode * make_tree( vector<int>& postorder,int postStart, int postEnd, vector<int>& inorder,
    int inStart, int inEnd, map<int, int>&mpp){
        if(postStart < postEnd || inStart> inEnd)return NULL;
        TreeNode * root = new TreeNode(postorder[postStart]);
        int inroot=mpp[root->val];
        int  numsright= inEnd-inroot;

        root->right=make_tree(postorder, postStart-1, postStart-numsright, inorder, inroot+1, inEnd, mpp);
        root->left=make_tree(postorder, postStart-numsright-1, postEnd, inorder, inStart, inroot-1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return make_tree(postorder, postorder.size()-1, 0, inorder, 0 , inorder.size()-1, mpp);
    }

};