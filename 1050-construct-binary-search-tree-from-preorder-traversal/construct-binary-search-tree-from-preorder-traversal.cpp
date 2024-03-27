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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);

        for(int i=1;i<preorder.size();i++){
            TreeNode* cur=root, * prev=NULL;
            int flag=0;//0->left and 1->right
            while(cur!=NULL){
                prev=cur;
                if(preorder[i]<cur->val){
                    flag=0;
                    cur=cur->left;
                }
                else{ 
                    flag=1;
                    cur=cur->right;
                }
            }
            if(flag==0)prev->left=new TreeNode(preorder[i]);
            else prev->right=new TreeNode(preorder[i]);
        }
        return root;
    }
};