/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void f(Node* root, vector<int>&traversal){
        if(root==NULL)return;

        for(auto it:root->children){
            f(it,traversal);
        }
        traversal.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>traversal;
        f(root, traversal);
        return traversal;
    }
};