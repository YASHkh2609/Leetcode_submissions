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
    int getsum(TreeNode * root, int &maxsum){
        if(root==NULL)return 0;

        int leftsum=getsum(root->left, maxsum);
        int rightsum=getsum(root->right, maxsum);

        maxsum=max(maxsum, leftsum+rightsum+root->val);
        if((root->val+ max(leftsum,rightsum))<0)return 0;//we shouldn't take -ve path sums so return 0 instead of taking them
        else return root->val+ max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int sum=getsum(root, maxsum);
        return maxsum;
    }
};