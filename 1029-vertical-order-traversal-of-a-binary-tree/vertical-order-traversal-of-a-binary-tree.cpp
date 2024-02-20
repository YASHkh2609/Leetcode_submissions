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
    void get_verticalTraversal(TreeNode* root,map<int, map<int, vector<int>>>&mpp, int row, int col){
        if(root==NULL)return;

        get_verticalTraversal(root->left, mpp, row+1, col-1);
        mpp[col][row].push_back(root->val);
        get_verticalTraversal(root->right, mpp, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>>mpp;
        get_verticalTraversal(root, mpp, 0,0);

        vector<vector<int>>ans;

        for(auto itr=mpp.begin(); itr!=mpp.end(); itr++){
            vector<int> level;
            for(auto ptr= itr->second.begin(); ptr!=itr->second.end(); ptr++){
                sort(ptr->second.begin(), ptr->second.end());
                level.insert(level.end(), ptr->second.begin(), ptr->second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};