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
    TreeNode* postOrder(TreeNode* root, set<int>&to_delete, vector<TreeNode*>&forest){
        if(root==NULL)return NULL;

        root->left = postOrder(root->left, to_delete, forest);
        root->right = postOrder(root->right, to_delete, forest);

        //process the root

        if(to_delete.find(root->val)==to_delete.end()){
            return root;
        }

        //it is to be deleted
        if(root->left)forest.push_back(root->left);
        if(root->right)forest.push_back(root->right);

        root->left=NULL;
        root->right=NULL;
        return NULL;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>to_be_deleted(to_delete.begin(),to_delete.end());
        vector<TreeNode*>forest;
        TreeNode* node = postOrder(root, to_be_deleted, forest);

        if(node!=NULL)forest.push_back(root);

        return forest;
    }
};