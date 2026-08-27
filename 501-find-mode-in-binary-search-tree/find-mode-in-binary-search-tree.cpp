class Solution {
private:
    int previous = 0;
    int currentCount = 0;
    int maxCount = 0;
    bool first = true;

    vector<int> result;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (first || root->val != previous) {
            currentCount = 1;
            first = false;
        } else {
            currentCount++;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(root->val);
        } else if (currentCount == maxCount) {
            result.push_back(root->val);
        }

        previous = root->val;

        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};