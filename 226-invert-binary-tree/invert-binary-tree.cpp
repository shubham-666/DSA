class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        // Swap left and right children
        swap(root->left, root->right);

        // Invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};