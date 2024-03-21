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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        long long width=0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        while(!q.empty()){
            int size=q.size();
            long long lmin=q.front().second;
            long long first, last;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front().first;
                long long cur_id=q.front().second-lmin;
                q.pop();
                if(i==0)first=cur_id;
                if(i==size-1)last=cur_id;

                if(temp->left)q.push({temp->left, cur_id*2+1});
                if(temp->right)q.push({temp->right, cur_id*2+2});
            }
            width=max(width, last-first+1);
        }
        return width;

    }
};