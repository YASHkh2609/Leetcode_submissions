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
    void Inorder1(TreeNode* root, vector<int>& traversal){
        if(root==NULL){
            traversal.push_back(-101);
            return;
        }
        traversal.push_back(root->val);
        Inorder1(root->left, traversal);
        Inorder1(root->right, traversal);
    }
    void Inorder2(TreeNode* root, vector<int>& traversal){
        if(root==NULL){
            traversal.push_back(-101);
            return;
        }
        traversal.push_back(root->val);
        Inorder2(root->right, traversal);
        Inorder2(root->left, traversal);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return true;

        vector<int> left, right;
        Inorder1(root->left, left);
        Inorder2(root->right, right);

        for(int i=0;i<left.size();i++){
            if(left[i]!=right[i])return false;
        }
        return true;
    }
};