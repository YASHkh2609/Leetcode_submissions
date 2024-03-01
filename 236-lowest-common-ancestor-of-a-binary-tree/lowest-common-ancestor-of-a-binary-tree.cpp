/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool get_path(TreeNode* root, TreeNode* node, vector<TreeNode* >&path){
    //     if(!root)return false;

    //     path.push_back(root);
    //     if(root==node)return true;

    //     if(get_path(root->left, node, path) || get_path(root->right, node, path))return true;

    //     path.pop_back();
    //     return false;

    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode* >pPath,qPath;

        // bool path1=get_path(root, p, pPath);
        // bool path2=get_path(root, q, qPath);

        // TreeNode * ans;
        // for(int i=0;i<min(pPath.size(), qPath.size());i++){
        //     if(pPath[i]==qPath[i])ans=pPath[i];
        // }
        // return ans;
        if(root==NULL || root==p|| root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left, p,q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);

        if(left==NULL)return right;
        else if(right==NULL)return left;
        return root;
        
    }
};