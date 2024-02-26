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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * NodeToInsert=new TreeNode(val);
         if(root==NULL)return NodeToInsert;
        // TreeNode * prev=NULL, * cur=root;
        // bool flag=1;
        // while(cur){
        //     if(val<cur->val){
        //         prev=cur;
        //         cur=cur->left;
        //         flag=0;
        //     }
        //     else{
        //         prev=cur;
        //         cur=cur->right;
        //         flag=1;
        //     }

        // } 
        // if(flag==0)prev->left=NodeToInsert;
        // else prev->right=NodeToInsert;
        TreeNode* cur=root;
        while(true){
            if(val<cur->val){ //check for left
                if(cur->left!=NULL)cur=cur->left;//if not leaf, go left
                else{
                    cur->left=NodeToInsert;//if leaf, insert
                    break;
                }
            }
            else{//check for right
                if(cur->right!=NULL)cur=cur->right;//if not leaf, go right
                else{
                    cur->right=NodeToInsert;//if leaf, insert
                    break;
                }
            }
        }
        return root;
    }
};