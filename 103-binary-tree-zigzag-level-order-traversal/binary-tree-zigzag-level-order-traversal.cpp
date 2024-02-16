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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;

        queue<TreeNode*>q;
        q.push(root);
        bool leftToright=true;// true when normal insertion , false when opposite
        while(!q.empty()){
            vector<int>level;
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(leftToright)level.push_back(temp->val);
                else level.insert(level.begin(), temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ans.push_back(level);      
            leftToright=!leftToright;
        }
        return ans;
    }

};