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
private: 
    TreeNode * find_node(TreeNode* root, TreeNode * target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp==target)return temp;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return NULL;
    }
    void get_parent_ptr(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent_ptr){
        queue<TreeNode*>q;
        q.push(root);
        parent_ptr[root]=NULL;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent_ptr[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent_ptr[temp->right]=temp;
            }
        }
    }    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*, TreeNode*>parent_ptr;
        get_parent_ptr(root, parent_ptr);

        TreeNode * newroot = find_node(root, target);
        unordered_map<TreeNode*, bool>vis;

        queue<TreeNode*>q;
        q.push(newroot);
        vis[newroot]=1;

        int dist=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                level.push_back(temp->val);
                if(parent_ptr[temp] && !vis[parent_ptr[temp]]){
                    q.push(parent_ptr[temp]);
                    vis[parent_ptr[temp]]=1;
                }
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
            }
            if(dist==k){
                ans=level;
                break;
            }
            dist++;
        }
        return ans;
    }
};