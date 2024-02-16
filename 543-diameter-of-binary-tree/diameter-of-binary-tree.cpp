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
    int height(TreeNode* root, vector<int>&ans){
        if(root==NULL)return 0;

        int lh=height(root->left, ans);
        int rh=height(root->right, ans);
        ans.push_back(lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        vector<int>ans;
        int h = height(root, ans);
        sort(ans.begin(), ans.end());
        return ans.back();        
    }
};