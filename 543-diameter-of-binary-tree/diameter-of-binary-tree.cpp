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
    int height1(TreeNode* root){
        if(root==NULL)return 0;

        int lh=height1(root->left);
        int rh=height1(root->right);

        return 1+max(lh,rh);
    }
    int maxi=0;
    void give_diameter(TreeNode* root, int &maxi){
        if(root==NULL) return;

        int lh=height1(root->left);
        int rh=height1(root->right);

        maxi=max(maxi, lh+rh);
        give_diameter(root->left, maxi);
        give_diameter(root->right, maxi);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Below soln is O(N^2) and uses an extra space
        // if(root==NULL)return 0;
        // vector<int>ans;
        // int h = height(root, ans);
        // sort(ans.begin(), ans.end());
        // return ans.back();        
        
        //Better solution 
        give_diameter(root, maxi);
        return maxi;
    }
};