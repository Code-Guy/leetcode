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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorderTraversalIterative(root, nodes);
        return nodes;
    }
    
private:
    void inorderTraversalRecursive(TreeNode* node, vector<int> &nodes) {
        if (node == NULL) return;
        inorderTraversalRecursive(node->left, nodes);
        nodes.push_back(node->val);
        inorderTraversalRecursive(node->right, nodes);
    }
    
    void inorderTraversalIterative(TreeNode* node, vector<int> &nodes) {
        stack<TreeNode *> s;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            }
            else {
                node = s.top();
                s.pop();
                nodes.push_back(node->val);
                node = node->right;
            }
        }
    }
};
