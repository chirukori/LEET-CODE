class Solution {
public:
    void preorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};