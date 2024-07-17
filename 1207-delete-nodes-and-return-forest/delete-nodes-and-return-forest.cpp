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
    void get_ultimate_parent(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&Uparent){
        if(root->left){
            Uparent[root->left]=Uparent[root];
            get_ultimate_parent(root->left, Uparent);
        }
        if(root->right){
            Uparent[root->right]=Uparent[root];
            get_ultimate_parent(root->right, Uparent);
        }
    }
    void get_immediate_parent(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&Iparent){
        if(root->left){
            Iparent[root->left]=root;
            get_immediate_parent(root->left, Iparent);
        }
        if(root->right){
            Iparent[root->right]=root;
            get_immediate_parent(root->right, Iparent);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<TreeNode*, TreeNode*>Uparent;
        unordered_map<TreeNode*, TreeNode*>Iparent;
        Uparent[root]=root;
        Iparent[root]=NULL;
        get_ultimate_parent(root, Uparent);    
        get_immediate_parent(root, Iparent);

        for(auto it:to_delete){
            TreeNode* nodeToBeDeleted;
            for(auto itr:Uparent){
                if(it==itr.first->val)nodeToBeDeleted=itr.first;
            }
            Uparent[nodeToBeDeleted]=NULL;
            if(Iparent[nodeToBeDeleted]!=NULL){
                if(nodeToBeDeleted==Iparent[nodeToBeDeleted]->left)
                    Iparent[nodeToBeDeleted]->left=NULL;
                else
                    Iparent[nodeToBeDeleted]->right=NULL;
                Iparent[nodeToBeDeleted]=NULL;
            }

            if(nodeToBeDeleted->left){
                Iparent[nodeToBeDeleted->left]=NULL;
                Uparent[nodeToBeDeleted->left]=nodeToBeDeleted->left;
                get_ultimate_parent(nodeToBeDeleted->left, Uparent);
            }
            if(nodeToBeDeleted->right){
                Iparent[nodeToBeDeleted->right]=NULL;
                Uparent[nodeToBeDeleted->right]=nodeToBeDeleted->right;
                get_ultimate_parent(nodeToBeDeleted->right, Uparent);
            }
            nodeToBeDeleted->left=NULL;
            nodeToBeDeleted->right=NULL;
        }    
        vector<TreeNode*>ans;
        for(auto it:Uparent){
            if(it.second!=NULL && it.first==it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};