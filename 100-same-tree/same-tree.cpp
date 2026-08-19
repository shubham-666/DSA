class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // One node is NULL
        if (p == NULL || q == NULL)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};