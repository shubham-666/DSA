class Solution {
private:
    void dfs(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        for (Node* child : root->children) {
            dfs(child, result);
        }

        result.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};