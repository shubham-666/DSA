class Solution {
private:
    TreeNode* previous = nullptr;
    int minimum = INT_MAX;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (previous != nullptr) {
            minimum = min(minimum, root->val - previous->val);
        }

        previous = root;

        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minimum;
    }
};
