class Solution {
private:
    int totalTilt = 0;

    int subtreeSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = subtreeSum(root->left);
        int rightSum = subtreeSum(root->right);

        totalTilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        subtreeSum(root);
        return totalTilt;
    }
};