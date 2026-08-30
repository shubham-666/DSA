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
    int findSecondMinimumValue(TreeNode* root) {
   long long ans = LLONG_MAX;

        dfs(root, root->val, ans);

        return ans == LLONG_MAX ? -1 : (int)ans;
    }

    void dfs(TreeNode* node, int minimum, long long& ans) {
        if (node == nullptr)
            return;

        if (node->val > minimum) {
            ans = min(ans, (long long)node->val);
            return;
        }

        dfs(node->left, minimum, ans);
        dfs(node->right, minimum, ans);
    }
};