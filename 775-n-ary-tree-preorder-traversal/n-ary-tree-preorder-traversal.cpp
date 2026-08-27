class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        result.push_back(root->val);

        for (Node* child : root->children) {
            vector<int> childResult = preorder(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }

        return result;
    }
};