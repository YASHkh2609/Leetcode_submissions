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
    bool check_valid(TreeNode * root, long long lb, long long ub){
        if(root==NULL)return true;
        bool check = (root->val>lb && root->val<ub);
        return check && check_valid(root->left, lb, root->val) && check_valid(root->right, root->val, ub);
    }
    bool isValidBST(TreeNode* root) {
        return check_valid(root, LLONG_MIN, LLONG_MAX);
    }
};