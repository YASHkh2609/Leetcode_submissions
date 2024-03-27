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
    TreeNode * make_tree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,
    int inStart, int inEnd, map<int,int>&mpp){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        TreeNode * root = new TreeNode(preorder[preStart]);

        int inroot=mpp[root->val];
        int numsleft=inroot-inStart;

        root->left=make_tree(preorder, preStart+1, numsleft+preStart, inorder, inStart, inroot-1, mpp);
        root->right= make_tree(preorder, preStart+numsleft+1, preEnd, inorder, inroot+1, inEnd, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return make_tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
    }
};