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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> subtreeSums;
        unordered_map<int, int> umap;
        traverseTree(root, umap);
        int maxFreq = 0;
        for (auto iter : umap) {
            if (iter.second == maxFreq) subtreeSums.push_back(iter.first);
            else if (iter.second > maxFreq) {
                maxFreq = iter.second;
                subtreeSums.clear();
                subtreeSums.push_back(iter.first);
            }
        }
        return subtreeSums;
    }
    
private:
    void traverseTree(TreeNode *node, unordered_map<int, int> &umap) {
        if (node == NULL) return;
        int sum = subtreeSum(node);
        if (umap.find(sum) == umap.end()) umap[sum] = 1;
        else umap[sum]++;
        traverseTree(node->left, umap);
        traverseTree(node->right, umap);
    }
    
    int subtreeSum(TreeNode *node) {
        if (node == NULL) return 0;
        return node->val + subtreeSum(node->left) + subtreeSum(node->right);
    }
};
