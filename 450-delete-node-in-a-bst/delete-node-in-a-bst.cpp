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
    TreeNode* deleteHelper(TreeNode* root){
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;

        TreeNode* right_child=root->right;
        TreeNode* rightmost_child = rightmostChild(root->left);
        rightmost_child->right=right_child;

        return root->left;
    }
    TreeNode* rightmostChild(TreeNode* root){
        while(root->right!=NULL)root=root->right;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            return deleteHelper(root);
        }

        TreeNode* temp=root;
        while(temp!=NULL){
            if(key<temp->val){
                if(temp->left!=NULL && temp->left->val==key){
                    temp->left=deleteHelper(temp->left);
                    break;
                }
                else temp=temp->left;
            }
            else{
                if(key>temp->val){
                    if(temp->right!=NULL && temp->right->val==key){
                        temp->right=deleteHelper(temp->right);
                        break;
                    }
                    else temp=temp->right;
                }
            }
        }
        return root;
    }
};