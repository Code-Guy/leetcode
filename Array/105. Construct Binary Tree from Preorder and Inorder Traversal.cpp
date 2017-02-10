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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    
private:
    TreeNode* buildTree(const vector<int> &preorder, const vector<int> &inorder, 
        int pb, int pe, int ib, int ie)
    {
        if (pe == pb) {
            return NULL;
        }
        if (pe == pb + 1) {
            return new TreeNode(preorder[pb]);
        }
        
        int root = preorder[pb];
        TreeNode *node = new TreeNode(root);
        int r = find(inorder.begin() + ib, inorder.begin() + ie, root) - (inorder.begin() + ib);
        node->left = buildTree(preorder, inorder, pb + 1, pb + r + 1, ib, ib + r);
        node->right = buildTree(preorder, inorder, pb + r + 1, pe, ib + r + 1, ie);
        
        return node;
    }
};
