class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = max(a.best, b.best);

        // Entire left + right prefix have same character
        if (a.prefix == a.len && a.leftChar == b.leftChar)
            res.prefix = a.len + b.prefix;

        // Entire right + left suffix have same character
        if (b.suffix == b.len && a.rightChar == b.leftChar)
            res.suffix = b.len + a.suffix;

        // Join suffix of left and prefix of right
        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suffix + b.prefix);

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.resize(4 * n + 5);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};