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
private:
    void inOrderTraversal(TreeNode* root, vector<int>&inOrder){
        if(root==NULL)return;

        inOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right, inOrder);
    }
    void replaceValues(TreeNode* root, vector<int>&inOrder){
        if(root==NULL)return;

        replaceValues(root->left, inOrder);
        int greaterSum=0;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i]>root->val){
                greaterSum+=inOrder[i];
            }
        }
        root->val = root->val + greaterSum;
        replaceValues(root->right, inOrder);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>inOrder;
        inOrderTraversal(root, inOrder);
        reverse(inOrder.begin(), inOrder.end());
        replaceValues(root,inOrder);
        return root;
    }
};