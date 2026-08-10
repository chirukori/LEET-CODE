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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        // If it's a leaf node, check if node value equals remaining targetSum
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Subtract current node's value and recurse on children
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || 
               hasPathSum(root->right, remainingSum);
        
    }
};