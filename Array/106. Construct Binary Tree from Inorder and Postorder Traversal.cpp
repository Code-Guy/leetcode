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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    
private:
    TreeNode* buildTree(const vector<int> &inorder, const vector<int> &postorder, 
        int ib, int ie, int pb, int pe)
    {
        if (pe == pb) {
            return NULL;
        }
        if (pe == pb + 1) {
            return new TreeNode(postorder[pb]);
        }
        
        int root = postorder[pe - 1];
        TreeNode *node = new TreeNode(root);
        int r = find(inorder.begin() + ib, inorder.begin() + ie, root) - (inorder.begin() + ib);
        node->left = buildTree(inorder, postorder, ib, ib + r, pb, pb + r);
        node->right = buildTree(inorder, postorder, ib + r + 1, ie, pb + r, pe - 1);
        
        return node;
    }
};
